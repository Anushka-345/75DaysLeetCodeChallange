class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # count stores the number of valid subarrays found
        count = 0
        # current_sum tracks the cumulative sum from the start
        current_sum = 0
        
        # prefix_sums stores {prefix_sum: frequency}
        # We initialize it with {0: 1} to handle cases where 
        # the current_sum itself equals k.
        prefix_sums = {0: 1}
        
        for num in nums:
            current_sum += num
            
            # Check if (current_sum - k) has occurred before
            target = current_sum - k
            if target in prefix_sums:
                count += prefix_sums[target]
            
            # Update the frequency of the current prefix sum in the map
            prefix_sums[current_sum] = prefix_sums.get(current_sum, 0) + 1
            
        return count
        