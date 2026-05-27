class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Arrays to store indices for 26 English letters
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        // Populate the tracking arrays
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (islower(ch)) {
                last_lower[ch - 'a'] = i; // Overwrite to always keep the last occurrence
            } else if (isupper(ch)) {
                int idx = ch - 'A';
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i; // Only record the first occurrence
                }
            }
        }
        
        int special_count = 0;
        
        // Verify conditions for each letter
        for (int i = 0; i < 26; ++i) {
            // Must exist in both lower and upper case, and last lower must come before first upper
            if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                special_count++;
            }
        }
        
        return special_count;
    }
};