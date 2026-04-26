class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;

        int n = words.size();

        // store reversed words
        for (int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            string &word = words[i];
            int len = word.size();

            for (int j = 0; j <= len; j++) {
                
                string left = word.substr(0, j);
                string right = word.substr(j);

                // Case 1: left is palindrome
                if (isPalindrome(word, 0, j - 1)) {
                    if (mp.count(right) && mp[right] != i) {
                        res.push_back({mp[right], i});
                    }
                }

                // Case 2: right is palindrome
                if (j != len && isPalindrome(word, j, len - 1)) {
                    if (mp.count(left) && mp[left] != i) {
                        res.push_back({i, mp[left]});
                    }
                }
            }
        }

        return res;
    }
};