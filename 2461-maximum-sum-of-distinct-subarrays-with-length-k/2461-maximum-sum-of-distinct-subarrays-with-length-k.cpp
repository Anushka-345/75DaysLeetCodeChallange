#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // frequency of elements in window
        long long currSum = 0;
        long long maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            freq[nums[right]]++;

            // Shrink window if it exceeds size k
            if (right - left + 1 > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }

            // Check if current window has exactly k distinct elements
            if (right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};