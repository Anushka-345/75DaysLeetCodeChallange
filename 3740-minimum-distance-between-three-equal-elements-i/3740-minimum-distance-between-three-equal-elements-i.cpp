class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // Store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Process each value
        for (auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();

            if (m < 3) continue;

            // Try consecutive triples
            for (int i = 0; i <= m - 3; i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};