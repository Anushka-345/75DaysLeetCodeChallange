class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }

            s.insert(nums[i]);

            // Maintain window of size k
            if (i >= k) {
                s.erase(nums[i - k]);
            }
        }

        return false;
    }
};