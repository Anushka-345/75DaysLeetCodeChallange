class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 1) return false; // base[1] is the smallest possible [1, 1]

        sort(nums.begin(), nums.end());

        // Check 1 to n-1
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }

        // Check the last two elements (both should be n)
        return nums[n - 1] == n && nums[n] == n;
    }
};