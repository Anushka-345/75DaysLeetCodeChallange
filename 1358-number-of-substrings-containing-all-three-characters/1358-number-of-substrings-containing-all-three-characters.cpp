class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0); // a, b, c
        int n = s.size();
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += (n - r);  // all substrings ending at r
                freq[s[l] - 'a']--;
                l++;
            }
        }

        return ans;
    }
};