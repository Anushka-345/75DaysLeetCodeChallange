class Solution {
private:
    // Helper function to check if two strings are anagrams
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        // The first word will always stay because it has no left neighbor to be compared with
        result.push_back(words[0]);
        
        // Start checking from the second word onwards
        for (int i = 1; i < words.size(); i++) {
            // Compare the current word with the LAST word that was kept in the result
            if (!isAnagram(words[i], result.back())) {
                result.push_back(words[i]);
            }
        }
        
        return result;
    }
};