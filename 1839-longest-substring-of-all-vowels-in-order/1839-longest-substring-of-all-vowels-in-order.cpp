#include <string>
#include <algorithm>

class Solution {
public:
    int longestBeautifulSubstring(std::string word) {
        int n = word.length();
        if (n < 5) return 0; // A beautiful substring needs at least 5 characters ('a','e','i','o','u')

        int max_len = 0;
        // Initialize for the first character
        int current_len = 1;
        int unique_vowels = 1;

        for (int i = 1; i < n; ++i) {
            if (word[i] >= word[i - 1]) {
                // Alphabetical order is maintained
                current_len++;
                if (word[i] != word[i - 1]) {
                    unique_vowels++; // Encountered a new unique vowel
                }
            } else {
                // Order is broken, reset trackers
                if (word[i] == 'a') {
                    current_len = 1;
                    unique_vowels = 1;
                } else {
                    current_len = 0;
                    unique_vowels = 0;
                }
            }

            // If all 5 unique vowels are present in correct order, update max_len
            if (unique_vowels == 5) {
                max_len = std::max(max_len, current_len);
            }
        }

        return max_len;
    }
};