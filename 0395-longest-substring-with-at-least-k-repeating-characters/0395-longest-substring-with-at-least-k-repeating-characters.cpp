class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0 || k > n) return 0;
        if (k <= 1) return n;

        // Count frequencies of each character in the current string/substring
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        // Find the first character that splits the string
        int i = 0;
        while (i < n && count[s[i] - 'a'] >= k) {
            i++;
        }

        // If every character satisfies the condition, the entire string is valid
        if (i == n) return n;

        // Otherwise, split the string at this invalid character 's[i]'
        // The result will be the maximum of the valid substrings found on the left and right
        int left_valid = longestSubstring(s.substr(0, i), k);
        
        // Skip any consecutive invalid characters to optimize performance
        while (i < n && count[s[i] - 'a'] < k) {
            i++;
        }
        
        int right_valid = (i < n) ? longestSubstring(s.substr(i), k) : 0;

        return max(left_valid, right_valid);
    }
};