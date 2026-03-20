class Solution(object):
    def minAbsDiff(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]
        
        for i in range(m - k + 1):
            for j in range(n - k + 1):
                # Collect all distinct values in the k x k submatrix
                values = set()
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        values.add(grid[x][y])
                
                if len(values) == 1:
                    ans[i][j] = 0
                else:
                    sorted_vals = sorted(values)
                    min_diff = float('inf')
                    for a, b in zip(sorted_vals, sorted_vals[1:]):
                        min_diff = min(min_diff, abs(b - a))
                    ans[i][j] = min_diff
        
        return ans
        