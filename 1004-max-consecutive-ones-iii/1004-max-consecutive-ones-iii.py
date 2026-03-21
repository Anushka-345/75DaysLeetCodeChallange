class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left = 0
        max_length = 0
        zero_count = 0
        
        for right in range(len(nums)):
            # If we encounter a 0, "use" one of our k flips
            if nums[right] == 0:
                zero_count += 1
            
            # If we've used more than k flips, shrink the window from the left
            while zero_count > k:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1
            
            # The window [left, right] is now valid (contains <= k zeros)
            max_length = max(max_length, right - left + 1)
            
        return max_length