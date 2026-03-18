class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows, cols = len(grid), len(grid[0])

        left = [[0] * cols for _ in range(rows)]
        up = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    left[i][j] = 1 + (left[i][j - 1] if j > 0 else 0)
                    up[i][j] = 1 + (up[i - 1][j] if i > 0 else 0)

        max_side = 0

        for i in range(rows):
            for j in range(cols):
                side = min(left[i][j], up[i][j])

                while side > max_side:
                    top_row = i - side + 1
                    left_col = j - side + 1

                    if up[i][left_col] >= side and left[top_row][j] >= side:
                        max_side = side
                        break

                    side -= 1

        return max_side * max_side
