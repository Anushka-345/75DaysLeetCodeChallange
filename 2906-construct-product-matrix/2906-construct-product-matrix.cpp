class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        vector<int> arr;
        
        // Step 1: Flatten matrix
        for (auto &row : grid) {
            for (auto &x : row) {
                arr.push_back(x % mod);
            }
        }
        
        int size = arr.size();
        
        vector<int> prefix(size, 1), suffix(size, 1);
        
        // Step 2: Prefix
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }
        
        // Step 3: Suffix
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }
        
        // Step 4: Build result
        vector<vector<int>> result(n, vector<int>(m));
        
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (prefix[k] * suffix[k]) % mod;
                k++;
            }
        }
        
        return result;
    }
};