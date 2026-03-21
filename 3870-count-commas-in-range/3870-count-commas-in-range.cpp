class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;

        if (n >= 1000)
            ans += min(n, 999999) - 1000 + 1;

        if (n >= 1000000)
            ans += 2LL * (min((long long)n, 999999999LL) - 1000000 + 1);

        if (n >= 1000000000)
            ans += 3LL * ((long long)n - 1000000000 + 1);

        return ans;
    }
};