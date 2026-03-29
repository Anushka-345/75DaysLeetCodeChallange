class Solution(object):
    def minAbsoluteDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last_one = -1
        last_two = -1
        min_diff = float('inf')
        
        for i, val in enumerate(nums):
            if val == 1:
                last_one = i
                # If we've seen a 2 before, calculate the distance
                if last_two != -1:
                    min_diff = min(min_diff, abs(last_one - last_two))
            
            elif val == 2:
                last_two = i
                # If we've seen a 1 before, calculate the distance
                if last_one != -1:
                    min_diff = min(min_diff, abs(last_two - last_one))
        
        # If min_diff was never updated, no valid pair exists
        return min_diff if min_diff != float('inf') else -1
        