class Solution {
public:
    bool isPrefixAndSuffix(string &a, string &b) {
        int n = a.size(), m = b.size();
        if (n > m) return false;

        // check prefix
        if (b.substr(0, n) != a) return false;

        // check suffix
        if (b.substr(m - n, n) != a) return false;

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};