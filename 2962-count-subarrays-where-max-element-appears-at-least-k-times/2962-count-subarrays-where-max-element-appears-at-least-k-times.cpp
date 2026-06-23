class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        long long ans = 0;
        int l = 0, count = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == mx) count++;

            while (count >= k) {
                ans += (n - r); // all subarrays ending at r or beyond
                if (nums[l] == mx) count--;
                l++;
            }
        }
        return ans;
    }
};