class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        unordered_map<char, int> charCount;

        int l = 0, distinct = 0;
        int n = s.size();

        // build first window
        for (int r = 0; r < n; r++) {
            charCount[s[r]]++;

            // maintain window size = minSize
            if (r - l + 1 > minSize) {
                charCount[s[l]]--;
                if (charCount[s[l]] == 0) {
                    charCount.erase(s[l]);
                }
                l++;
            }

            if (r - l + 1 == minSize) {
                if (charCount.size() <= maxLetters) {
                    freq[s.substr(l, minSize)]++;
                }
            }
        }

        int ans = 0;
        for (auto &p : freq) {
            ans = max(ans, p.second);
        }

        return ans;
    }
};