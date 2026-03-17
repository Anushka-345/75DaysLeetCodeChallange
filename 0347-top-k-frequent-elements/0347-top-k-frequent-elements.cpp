class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Create buckets
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        
        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }
        
        // Step 3: Collect top k frequent elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};