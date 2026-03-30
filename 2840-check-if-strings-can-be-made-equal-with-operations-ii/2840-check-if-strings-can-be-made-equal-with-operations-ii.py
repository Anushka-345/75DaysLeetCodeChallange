class Solution(object):
    def checkStrings(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # Collect characters at even indices
        s1_even = sorted(s1[0::2])
        s2_even = sorted(s2[0::2])
        
        # Collect characters at odd indices
        s1_odd = sorted(s1[1::2])
        s2_odd = sorted(s2[1::2])
        
        # If the sorted groups match, the strings are equivalent
        return s1_even == s2_even and s1_odd == s2_odd
        