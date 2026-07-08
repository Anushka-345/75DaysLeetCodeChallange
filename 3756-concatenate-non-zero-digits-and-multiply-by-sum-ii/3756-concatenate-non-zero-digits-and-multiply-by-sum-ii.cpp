class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        int MOD = 1e9 + 7;
        
        // 1. Store non-zero digits and their original indices
        vector<int> vals, indices;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                vals.push_back(s[i] - '0');
                indices.push_back(i);
            }
        }
        
        // 2. Precompute prefix sums and powers of 10
        int n = vals.size();
        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefVal(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = (prefSum[i] + vals[i]) % MOD;
            prefVal[i + 1] = (prefVal[i] * 10 + vals[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }
        
        vector<int> answer;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            
            // Find range of non-zero digits within [l, r]
            auto it1 = lower_bound(indices.begin(), indices.end(), l);
            auto it2 = upper_bound(indices.begin(), indices.end(), r);
            
            int start = distance(indices.begin(), it1);
            int end = distance(indices.begin(), it2);
            
            if (start >= end) {
                answer.push_back(0);
            } else {
                // Get sum and concatenated number x
                long long rangeSum = (prefSum[end] - prefSum[start] + MOD) % MOD;
                long long x = (prefVal[end] - (prefVal[start] * pow10[end - start]) % MOD + MOD) % MOD;
                answer.push_back((x * rangeSum) % MOD);
            }
        }
        return answer;
    }
};