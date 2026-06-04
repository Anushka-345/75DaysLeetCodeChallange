#include <string>

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
            if (i < 100) {
                continue; // Numbers with fewer than 3 digits have 0 waviness
            }
            
            std::string s = std::to_string(i);
            int n = s.length();
            
            // Check middle digits (excluding first and last)
            for (int j = 1; j < n - 1; ++j) {
                if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
                    total_sum++; // It's a peak
                } else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
                    total_sum++; // It's a valley
                }
            }
        }
        
        return total_sum;
    }
};