class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: find break point
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: if found
        if (i >= 0) {
            int j = n - 1;

            // Step 3: find just greater element
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Step 4: swap
            swap(nums[i], nums[j]);
        }

        // Step 5: reverse suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};