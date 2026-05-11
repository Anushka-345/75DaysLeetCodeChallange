class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the starting point is an obstacle, no paths are possible.
        if (obstacleGrid[0][0] == 1) return 0;

        // dp[j] will store the number of ways to reach the current cell in column j
        vector<long long> dp(n, 0);
        
        // Base case: starting point
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    // Obstacle found, reset paths to 0
                    dp[j] = 0;
                } else if (j > 0) {
                    // Paths to (i, j) = Paths to (i-1, j) + Paths to (i, j-1)
                    // dp[j] already holds the value from the row above (i-1, j)
                    // dp[j-1] holds the value from the left (i, j-1)
                    dp[j] += dp[j-1];
                }
            }
        }

        return (int)dp[n - 1];
    }
};