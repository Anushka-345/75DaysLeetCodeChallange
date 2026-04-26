class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;

        for (auto &w : words) {
            freq[w]++;
        }

        int length = 0;
        bool centerUsed = false;

        for (auto &it : freq) {
            string w = it.first;
            int f = it.second;

            string rev = string({w[1], w[0]});

            // Skip if already processed reverse pair
            if (w[0] != w[1]) {
                if (freq.count(rev)) {
                    int pairs = min(freq[w], freq[rev]);
                    length += pairs * 4;
                    freq[w] -= pairs;
                    freq[rev] -= pairs;
                }
            }
        }

        // Handle same-letter words
        for (auto &it : freq) {
            string w = it.first;
            int f = it.second;

            if (w[0] == w[1]) {
                length += (f / 2) * 4;

                if (f % 2 == 1) {
                    centerUsed = true;
                }
            }
        }

        if (centerUsed) length += 2;

        return length;
    }
};