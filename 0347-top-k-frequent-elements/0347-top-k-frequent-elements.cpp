class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Frequency count → O(n)
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Bucket creation → O(n)
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        // Step 3: Collect top k → O(n)
        vector<int> res;
        for (int i = nums.size(); i >= 0 && res.size() < k; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};