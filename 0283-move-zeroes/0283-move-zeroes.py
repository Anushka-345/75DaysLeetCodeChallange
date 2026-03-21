class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # lastNonZeroIndex keeps track of the position to swap a non-zero element into
        lastNonZeroIndex = 0
        
        for current in range(len(nums)):
            if nums[current] != 0:
                # Swap the non-zero element with the element at lastNonZeroIndex
                nums[lastNonZeroIndex], nums[current] = nums[current], nums[lastNonZeroIndex]
                
                # Move the pointer forward
                lastNonZeroIndex += 1
        