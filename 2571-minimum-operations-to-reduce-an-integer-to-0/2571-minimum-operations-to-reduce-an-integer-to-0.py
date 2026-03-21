class Solution(object):
    def minOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {}

        def solve(num):
            if num == 0:
                return 0
            # If num is a power of 2, it takes exactly 1 operation
            if (num & (num - 1)) == 0:
                return 1
            if num in memo:
                return memo[num]
            
            # Find the lowest set bit (low_bit)
            low_bit = num & -num
            
            # Option 1: Subtract the low_bit (treat it as a 0)
            # Option 2: Add the low_bit (this carries over to higher bits)
            res = 1 + min(solve(num + low_bit), solve(num - low_bit))
            
            memo[num] = res
            return res
            
        return solve(n)