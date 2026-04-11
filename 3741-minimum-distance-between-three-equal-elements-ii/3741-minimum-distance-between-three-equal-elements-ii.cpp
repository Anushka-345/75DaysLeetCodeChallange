class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        // Store indices of each value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Process each value group
        for (auto &it : mp) {
            vector<int> &pos = it.second;
            
            if (pos.size() < 3) continue;
            
            // Check consecutive triples
            for (int i = 0; i + 2 < pos.size(); i++) {
                int dist = 2 * (pos[i + 2] - pos[i]);
                ans = min(ans, dist);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};