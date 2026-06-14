#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int rearrangeCharacters(std::string s, std::string target) {
        // Frequency arrays for lowercase English letters
        std::vector<int> countS(26, 0);
        std::vector<int> countTarget(26, 0);
        
        // Count frequencies in string s
        for (char ch : s) {
            countS[ch - 'a']++;
        }
        
        // Count frequencies in target string
        for (char ch : target) {
            countTarget[ch - 'a']++;
        }
        
        int maxCopies = INT_MAX;
        
        // Find the bottleneck character
        for (int i = 0; i < 26; ++i) {
            if (countTarget[i] > 0) {
                // If s doesn't have enough of a required character, we can't make any copies
                maxCopies = std::min(maxCopies, countS[i] / countTarget[i]);
            }
        }
        
        return maxCopies == INT_MAX ? 0 : maxCopies;
    }
};