class Solution(object):
    def maxProductPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])
        
        # dp[i][j] = (max_product_to_cell, min_product_to_cell)
        dp = [[(0, 0)] * n for _ in range(m)]
        dp[0][0] = (grid[0][0], grid[0][0])
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                val = grid[i][j]
                max_prod = float('-inf')
                min_prod = float('inf')
                
                # From top
                if i > 0:
                    prev_max, prev_min = dp[i-1][j]
                    max_prod = max(max_prod, val * prev_max, val * prev_min)
                    min_prod = min(min_prod, val * prev_max, val * prev_min)
                
                # From left
                if j > 0:
                    prev_max, prev_min = dp[i][j-1]
                    max_prod = max(max_prod, val * prev_max, val * prev_min)
                    min_prod = min(min_prod, val * prev_max, val * prev_min)
                
                dp[i][j] = (max_prod, min_prod)
        
        result = dp[m-1][n-1][0]
        return result % MOD if result >= 0 else -1