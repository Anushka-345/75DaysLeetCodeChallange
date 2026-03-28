class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
     int mx = 0;
        for(int x : nums){
            mx = max(mx, x);  // find the maximum value
        }

        long long left = 0;
        long long count = 0;  // count of mx in current window
        long long result = 0; // result should be long long

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == mx) count++;  // increment if mx found

            // BUG FIX: should be while(count >= k) instead of while(count < k)
            // because we want windows that **contain at least k mx**
            while(count >= k){
                result += nums.size() - right;  // all subarrays starting from left ending at >= right
                if(nums[left] == mx){
                    count--;  // shrink the window
                }
                left++;
            }
        }

        return result;
    }
};