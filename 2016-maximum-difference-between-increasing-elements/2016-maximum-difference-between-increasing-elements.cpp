class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minSoFar = nums[0];
        int ans = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > minSoFar) {
                ans = max(ans, nums[i] - minSoFar);
            } else {
                minSoFar = nums[i];
            }
        }

        return ans;
    }
};