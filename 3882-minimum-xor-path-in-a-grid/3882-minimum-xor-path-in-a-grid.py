class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        
        # dp[r][c] stores a set of all possible XOR sums to reach that cell
        dp = [[set() for _ in range(n)] for _ in range(m)]
        
        # Base case: starting point
        dp[0][0].add(grid[0][0])
        
        for r in range(m):
            for c in range(n):
                if r == 0 and c == 0:
                    continue
                
                # If we can come from the cell above
                if r > 0:
                    for prev_xor in dp[r-1][c]:
                        dp[r][c].add(prev_xor ^ grid[r][c])
                
                # If we can come from the cell to the left
                if c > 0:
                    for prev_xor in dp[r][c-1]:
                        dp[r][c].add(prev_xor ^ grid[r][c])
        
        # The minimum value in the last cell's set is our answer
        return min(dp[m-1][n-1])
        