class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: Group indices by value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        // Step 2: Process each group
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();
            
            vector<long long> prefix(k, 0);
            prefix[0] = idx[0];
            
            // Build prefix sum
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + idx[i];
            }
            
            for (int i = 0; i < k; i++) {
                long long left = (long long)idx[i] * i - (i > 0 ? prefix[i - 1] : 0);
                long long right = (prefix[k - 1] - prefix[i]) - (long long)idx[i] * (k - i - 1);
                
                result[idx[i]] = left + right;
            }
        }
        
        return result;
    }
};