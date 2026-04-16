class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: map value -> indices
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];

            // If only one occurrence
            if(vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // Binary search
            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int res = INT_MAX;

            // Check next index
            int next = vec[(idx + 1) % vec.size()];
            int dist1 = abs(q - next);
            res = min(res, min(dist1, n - dist1));

            // Check previous index
            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int dist2 = abs(q - prev);
            res = min(res, min(dist2, n - dist2));

            ans.push_back(res);
        }

        return ans;
    }
};