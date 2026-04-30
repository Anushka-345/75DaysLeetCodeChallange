class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][cost] = max_score
        // Initialize with -1 to represent unreachable states
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Base case: starting point (0,0)
        // Constraints state grid[0][0] is always 0, so cost is 0, score is 0.
        dp[0][0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int c = 0; c <= k; ++c) {
                    if (dp[i][j][c] == -1) continue;

                    // Try moving Down (i+1, j) or Right (i, j+1)
                    int directions[2][2] = {{1, 0}, {0, 1}};
                    for (auto& dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        if (ni < m && nj < n) {
                            int cellVal = grid[ni][nj];
                            int moveCost = (cellVal == 0) ? 0 : 1;
                            int moveScore = cellVal;

                            if (c + moveCost <= k) {
                                dp[ni][nj][c + moveCost] = max(dp[ni][nj][c + moveCost], dp[i][j][c] + moveScore);
                            }
                        }
                    }
                }
            }
        }

        // Find the maximum score in the last cell for any cost <= k
        int maxScore = -1;
        for (int c = 0; c <= k; ++c) {
            maxScore = max(maxScore, dp[m - 1][n - 1][c]);
        }

        return maxScore;
    }
};