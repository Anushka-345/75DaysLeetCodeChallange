from collections import deque

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        res = []
        # dq stores indices of elements in nums
        dq = deque()
        
        for i in range(len(nums)):
            # 1. Remove indices that are out of the current window range
            if dq and dq[0] < i - k + 1:
                dq.popleft()
            
            # 2. Remove indices of elements smaller than the current element
            # because they will never be the maximum again
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()
            
            # 3. Add the current element's index
            dq.append(i)
            
            # 4. Once we've reached the size of the first window, 
            # the front of the deque is our current max
            if i >= k - 1:
                res.append(nums[dq[0]])
                
        return res