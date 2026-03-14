class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths differ, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Initialize frequency array for 'a'-'z'
        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Increment for s
            count[t[i] - 'a']--; // Decrement for t
        }

        // Check if all counts are zero
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};