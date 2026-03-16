class Solution(object):
    def getBiggestThree(self, grid):
        m, n = len(grid), len(grid[0])
        
        # diag1: Top-left to bottom-right (\)
        # diag2: Top-right to bottom-left (/)
        # Using n+2 to safely handle c+1 and 1-based indexing
        diag1 = [[0] * (n + 2) for _ in range(m + 2)]
        diag2 = [[0] * (n + 2) for _ in range(m + 2)]
        
        for r in range(1, m + 1):
            for c in range(1, n + 1):
                diag1[r][c] = grid[r-1][c-1] + diag1[r-1][c-1]
                diag2[r][c] = grid[r-1][c-1] + diag2[r-1][c+1]
        
        res_set = set()
        
        for r in range(m):
            for c in range(n):
                # Every single cell is a rhombus of size 0
                res_set.add(grid[r][c])
                
                # s is the "radius" or distance from center to vertices
                for s in range(1, m):
                    # Define vertices
                    t_r, t_c = r, c           # Top
                    b_r, b_c = r + 2*s, c     # Bottom
                    l_r, l_c = r + s, c - s   # Left
                    r_r, r_c = r + s, c + s   # Right
                    
                    # Boundary check
                    if b_r >= m or l_c < 0 or r_c >= n:
                        break
                    
                    # Edge 1 (Top-Right): (t_r, t_c) to (r_r, r_c) -> diag1
                    e1 = diag1[r_r + 1][r_c + 1] - diag1[t_r][t_c]
                    # Edge 2 (Top-Left): (t_r, t_c) to (l_r, l_c) -> diag2
                    e2 = diag2[l_r + 1][l_c + 1] - diag2[t_r][t_c + 2]
                    # Edge 3 (Bottom-Right): (r_r, r_c) to (b_r, b_c) -> diag2
                    e3 = diag2[b_r + 1][b_c + 1] - diag2[r_r][r_c + 2]
                    # Edge 4 (Bottom-Left): (l_r, l_c) to (b_r, b_c) -> diag1
                    e4 = diag1[b_r + 1][b_c + 1] - diag1[l_r][l_c]
                    
                    # Sum all edges and subtract the 4 vertices (each was counted twice)
                    total = e1 + e2 + e3 + e4 - (grid[t_r][t_c] + grid[b_r][b_c] + grid[l_r][l_c] + grid[r_r][r_c])
                    res_set.add(total)
                    
        # Return the top 3 unique values sorted descending
        return sorted(list(res_set), reverse=True)[:3]