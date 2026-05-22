
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int start = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] != nums[i - 1] + 1) {
                start = i;
            }
            if (i >= k - 1) {
                ans.push_back((i - start + 1 >= k) ? nums[i] : -1);
            }
        }
        return ans;
    }
};