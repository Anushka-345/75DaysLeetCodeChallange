class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        count = [0] * 26  # Frequency of each uppercase letter
        left = 0
        max_count = 0  # Max frequency of a single char in the window
        max_length = 0
        
        for right in range(len(s)):
            index = ord(s[right]) - ord('A')
            count[index] += 1
            max_count = max(max_count, count[index])
            
            # If number of chars to change > k, shrink window
            if (right - left + 1) - max_count > k:
                count[ord(s[left]) - ord('A')] -= 1
                left += 1
            
            # Update max length
            max_length = max(max_length, right - left + 1)
        
        return max_length