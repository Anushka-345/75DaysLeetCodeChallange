class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int min_len = INT_MAX;
        long long current_sum = 0;

        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];

            // Try to shrink the window from the left while the sum is still >= target
            while (current_sum >= target) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        // If min_len was never updated, no valid subarray exists
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};