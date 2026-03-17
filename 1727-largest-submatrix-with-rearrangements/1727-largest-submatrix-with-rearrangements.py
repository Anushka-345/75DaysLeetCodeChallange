class Solution(object):
    def largestSubmatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        m = len(matrix)
        n = len(matrix[0])
        ans = 0
        
        # We only need to keep track of the heights for the current row
        heights = [0] * n
        
        for row in range(m):
            for col in range(n):
                # Calculate height of consecutive 1s ending at matrix[row][col]
                if matrix[row][col] == 1:
                    heights[col] += 1
                else:
                    heights[col] = 0
            
            # Create a copy and sort heights in descending order to maximize base
            # Sorting allows us to group the tallest bars together
            sorted_heights = sorted(heights, reverse=True)
            
            # Iterate through the sorted heights to find the max area at this row
            for i in range(n):
                # Height is sorted_heights[i], Base is (i + 1) columns
                area = sorted_heights[i] * (i + 1)
                ans = max(ans, area)
                
        return ans