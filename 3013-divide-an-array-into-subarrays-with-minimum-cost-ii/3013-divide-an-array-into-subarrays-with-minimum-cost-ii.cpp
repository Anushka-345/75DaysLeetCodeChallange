class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int m = k - 2; // Number of elements needed from the sliding window
        long long sumLow = 0;
        multiset<int> low, high;

        // Helper to balance sets: ensure 'low' contains the 'm' smallest elements
        auto balance = [&]() {
            while (low.size() < m && !high.empty()) {
                int val = *high.begin();
                sumLow += val;
                low.insert(val);
                high.erase(high.begin());
            }
            while (low.size() > m) {
                int val = *low.rbegin();
                sumLow -= val;
                high.insert(val);
                low.erase(prev(low.end()));
            }
        };

        auto add = [&](int val) {
            if (!low.empty() && val < *low.rbegin()) {
                sumLow += val;
                low.insert(val);
            } else {
                high.insert(val);
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);
            if (it != low.end()) {
                sumLow -= val;
                low.erase(it);
            } else {
                high.erase(high.find(val));
            }
            balance();
        };

        // Initial window for the very first possible second-subarray start (i = 1)
        // Candidates for the remaining k-2 indices are in range [2, 1 + dist]
        for (int i = 2; i <= 1 + dist && i < n; ++i) {
            add(nums[i]);
        }

        long long minCost = nums[0] + nums[1] + sumLow;

        // Slide the window: i is the start of the second subarray
        for (int i = 2; i <= n - (k - 1); ++i) {
            // Remove the element that just became the new fixed start 'i'
            remove(nums[i]);
            // Add the new element entering the window at the right boundary
            if (i + dist < n) {
                add(nums[i + dist]);
            }
            
            minCost = min(minCost, (long long)nums[0] + nums[i] + sumLow);
        }

        return minCost;
    }
};