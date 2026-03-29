class Solution(object):
    def countArrays(self, digitSum):
        """
        :type digitSum: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        MAX_VAL = 5000
        
        # 1. Precompute digit sums for all numbers 0 to 5000
        # group[s] stores all numbers in [0, 5000] that have digit sum s
        group = [[] for _ in range(50)] # Max digit sum for 4999 is 4+9+9+9=31, 5000 is 5. 
        for i in range(MAX_VAL + 1):
            s = sum(int(d) for d in str(i))
            if s < 50:
                group[s].append(i)
        
        n = len(digitSum)
        
        # Check if any digit sum is impossible (e.g., 49 as in Example 3)
        for s in digitSum:
            if s >= 50 or not group[s]:
                return 0

        # 2. Initialize DP for the first element
        # dp[v] = number of ways to end the current sequence with value v
        dp = [0] * (MAX_VAL + 1)
        for v in group[digitSum[0]]:
            dp[v] = 1
            
        # 3. Process the rest of the digitSum array
        for i in range(1, n):
            # Create a prefix sum array of the previous DP state
            # pref[v] = sum(dp[0...v])
            pref = [0] * (MAX_VAL + 2)
            current_sum = 0
            for v in range(MAX_VAL + 1):
                current_sum = (current_sum + dp[v]) % MOD
                pref[v + 1] = current_sum
            
            # Reset DP for the current index
            new_dp = [0] * (MAX_VAL + 1)
            target_sum = digitSum[i]
            
            # For each possible value v for the current index
            for v in group[target_sum]:
                # Non-decreasing constraint: prev_val <= v
                # We need the sum of all dp[prev_val] for prev_val in [0, v]
                new_dp[v] = pref[v + 1]
            
            dp = new_dp
            
        return sum(dp) % MOD
        