class Solution(object):
    def countVisiblePeople(self, n, pos, k):
        """
        :type n: int
        :type pos: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # Total people available to be seen is n - 1
        total_candidates = n - 1
        
        # If k is more than the people available, it's impossible
        if k > total_candidates:
            return 0
            
        # We need to calculate (n-1) choose k
        # Using the formula: nCr = n! / (r! * (n-r)!)
        def nCr_mod(n, r, m):
            if r < 0 or r > n:
                return 0
            if r == 0 or r == n:
                return 1
            if r > n // 2:
                r = n - r
            
            num = 1
            den = 1
            for i in range(r):
                num = (num * (n - i)) % m
                den = (den * (i + 1)) % m
            
            # Use Fermat's Little Theorem for modular inverse: a^(m-2) % m
            return (num * pow(den, m - 2, m)) % m

        combinations = nCr_mod(total_candidates, k, MOD)
        
        # Multiply by 2 for the person at 'pos'
        return (combinations * 2) % MOD