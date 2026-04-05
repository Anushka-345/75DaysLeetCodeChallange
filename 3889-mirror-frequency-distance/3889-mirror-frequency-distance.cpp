#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        unordered_set<char> seen;

        // Count frequencies
        for (char c : s) freq[c]++;

        int total = 0;

        for (auto &[c, f] : freq) {
            if (seen.count(c)) continue;

            char m;
            if (isalpha(c)) {
                m = 'a' + ('z' - c);  // Mirror for letters
            } else {  // digit
                m = '0' + ('9' - c);  // Mirror for digits
            }

            if (!seen.count(m)) {
                int freq_m = freq.count(m) ? freq[m] : 0;
                total += abs(f - freq_m);
            }

            seen.insert(c);
            seen.insert(m);
        }

        return total;
    }
};