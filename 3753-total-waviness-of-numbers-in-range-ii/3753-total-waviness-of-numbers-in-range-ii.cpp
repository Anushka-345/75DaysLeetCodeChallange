#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // DP memoization table: dp[idx][tight][is_leading][last][prev_last]
    // Dimensions: idx (up to 16), tight (2), is_leading (2), last (11), prev_last (11)
    // We use 10 to represent an unassigned/dummy value for empty slots.
    long long dp[16][2][2][11][11];

    long long dfs(const string& s, int idx, bool tight, bool is_leading, int last, int prev_last) {
        // Base case: if we have filled all digits, return 0 (no more waviness can be added)
        if (idx == s.length()) {
            return 0;
        }

        // Return memoized result if already computed
        if (dp[idx][tight][is_leading][last][prev_last] != -1) {
            return dp[idx][tight][is_leading][last][prev_last];
        }

        long long total_waviness = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; ++digit) {
            bool next_tight = tight && (digit == limit);
            bool next_leading = is_leading && (digit == 0);

            if (next_leading) {
                // If it's still a leading zero, pass down the dummy state (10)
                total_waviness += dfs(s, idx + 1, next_tight, true, 10, 10);
            } else {
                long long current_contribution = 0;
                
                // Check if the 'last' digit forms a peak or valley
                // It requires both prev_last and the current digit to be validly placed digits
                if (last != 10 && prev_last != 10) {
                    if ((last > prev_last && last > digit) || (last < prev_last && last < digit)) {
                        current_contribution = 1;
                    }
                }

                // If 'last' is a peak/valley, it contributes to ALL valid numbers formed by the remaining suffixes
                if (current_contribution > 0) {
                    current_contribution *= countValidNumbers(s, idx + 1, next_tight);
                }

                // Recurse to find waviness contributions from subsequent pairs
                total_waviness += current_contribution + dfs(s, idx + 1, next_tight, false, digit, last);
            }
        }

        return dp[idx][tight][is_leading][last][prev_last] = total_waviness;
    }

    // Helper function to count how many valid suffixes can be formed from this point
    long long countValidNumbers(const string& s, int idx, bool tight) {
        if (idx == s.length()) return 1;
        if (!tight) {
            // Shortcut: if not tight, any combination of 0-9 can be filled till the end
            long long count = 1;
            for (int i = idx; i < s.length(); ++i) count *= 10;
            return count;
        }
        
        long long count = 0;
        int limit = s[idx] - '0';
        for (int digit = 0; digit <= limit; ++digit) {
            count += countValidNumbers(s, idx + 1, tight && (digit == limit));
        }
        return count;
    }

    long long solve(long long num) {
        if (num < 100) return 0; // Any number with fewer than 3 digits has a waviness of 0
        string s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, true, true, 10, 10);
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};