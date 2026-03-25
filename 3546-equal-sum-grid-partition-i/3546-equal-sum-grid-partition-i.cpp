class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long totalSum = 0;

        // Step 1: Calculate total sum
        for (auto &row : grid) {
            for (auto val : row) {
                totalSum += val;
            }
        }

        // Step 2: If total sum is odd → impossible
        if (totalSum % 2 != 0) return false;

        long long target = totalSum / 2;

        // 🔹 Step 3: Check Horizontal Cuts
        long long rowSum = 0;
        for (int i = 0; i < m - 1; i++) { // ensure bottom part non-empty
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum == target) return true;
        }

        // 🔹 Step 4: Compute column sums
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }

        // 🔹 Step 5: Check Vertical Cuts
        long long prefixCol = 0;
        for (int j = 0; j < n - 1; j++) { // ensure right part non-empty
            prefixCol += colSum[j];
            if (prefixCol == target) return true;
        }

        return false;
    }
};