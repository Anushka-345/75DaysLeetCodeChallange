class Solution(object):
    def numberOfSubmatrices(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        
        # diff_row[j] stores (X_count - Y_count) for the rectangle (0,0) to (curr_i, j)
        # x_count_row[j] stores total 'X's for the same rectangle
        diff_row = [0] * cols
        x_count_row = [0] * cols
        
        res = 0
        
        for i in range(rows):
            curr_diff_sum = 0
            curr_x_sum = 0
            for j in range(cols):
                # Update horizontal running totals for the current row
                char = grid[i][j]
                if char == 'X':
                    curr_diff_sum += 1
                    curr_x_sum += 1
                elif char == 'Y':
                    curr_diff_sum -= 1
                
                # Add the values from the previous row (prefix sum logic)
                diff_row[j] += curr_diff_sum
                x_count_row[j] += curr_x_sum
                
                # Check constraints: 
                # 1. Equal X and Y (diff == 0)
                # 2. At least one X (x_count > 0)
                if diff_row[j] == 0 and x_count_row[j] > 0:
                    res += 1
                    
        return res