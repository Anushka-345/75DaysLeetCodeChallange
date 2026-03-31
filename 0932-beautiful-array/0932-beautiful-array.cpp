class Solution {
public:
    vector<int> beautifulArray(int n) {
         if (n == 1) return {1};
        
        vector<int> odd, even;
        
        // Recursively build odd part
        for (int x : beautifulArray((n + 1) / 2)) {
            odd.push_back(2 * x - 1);
        }
        
        // Recursively build even part
        for (int x : beautifulArray(n / 2)) {
            even.push_back(2 * x);
        }
        
        // Combine odd and even
        odd.insert(odd.end(), even.begin(), even.end());
        return odd;
    }
};