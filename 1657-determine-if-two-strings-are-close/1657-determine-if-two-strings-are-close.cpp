class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // 1. If lengths are different, they can never be close
        if (word1.size() != word2.size()) return false;
        
        vector<int> freq(26, 0);
        vector<int> b(26, 0);
        
        // Count frequencies of each character
        for (char c : word1) {
            freq[c - 'a']++;
        }
        for (char x : word2) {
            b[x - 'a']++;
        }
        
        // 2. Check if both words have the exact same unique character set
        for (int i = 0; i < 26; i++) {
            if ((freq[i] == 0 && b[i] != 0) || (b[i] == 0 && freq[i] != 0)) {
                return false;
            }
        }
        
        // 3. Check if they have the same frequency distribution
        sort(freq.begin(), freq.end());
        sort(b.begin(), b.end());
        
        // If the sorted frequency arrays match, return true
        return freq == b;
    }
};