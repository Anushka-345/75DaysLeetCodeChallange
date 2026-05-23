#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        // Max-heap for the lower half
        priority_queue<int> small;
        // Min-heap for the upper half (using greater<int> to make it a min-heap)
        priority_queue<int, vector<int>, greater<int>> large;
        // Hash map to keep track of numbers that need to be deleted lazily
        unordered_map<int, int> delayed;

        // Balance factor: small.size() - large.size()
        // We want small to have equal elements to large, or 1 more element if k is odd.
        int small_size = 0;
        int large_size = 0;

        // Helper function to prune invalid elements from the top of the heaps
        auto prune = [&](auto& heap, int& heap_size, bool is_small) {
            while (!heap.empty() && delayed[heap.top()] > 0) {
                delayed[heap.top()]--;
                heap.pop();
            }
        };

        // Helper function to rebalance the heaps
        auto balance = [&]() {
            if (small_size > large_size + 1) {
                large.push(small.top());
                small.pop();
                small_size--;
                large_size++;
                prune(small, small_size, true);
            } else if (small_size < large_size) {
                small.push(large.top());
                large.pop();
                small_size++;
                large_size--;
                prune(large, large_size, false);
            }
        };

        // Helper function to insert a number
        auto add = [&](int num) {
            if (small.empty() || num <= small.top()) {
                small.push(num);
                small_size++;
            } else {
                large.push(num);
                large_size++;
            }
            balance();
        };

        // Helper function to remove a number (lazily)
        auto remove = [&](int num) {
            delayed[num]++;
            if (num <= small.top()) {
                small_size--;
                if (num == small.top()) {
                    prune(small, small_size, true);
                }
            } else {
                large_size--;
                if (num == large.top()) {
                    prune(large, large_size, false);
                }
            }
            balance();
        };

        // Helper function to get the current median
        auto get_median = [&]() -> double {
            if (k & 1) {
                return small.top();
            } else {
                // Use long long to avoid integer overflow during addition
                return ((double)small.top() + large.top()) * 0.5;
            }
        };

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }
        medians.push_back(get_median());

        // Slide the window across the rest of the array
        for (int i = k; i < nums.size(); i++) {
            add(nums[i]);
            remove(nums[i - k]);
            medians.push_back(get_median());
        }

        return medians;
    }
};