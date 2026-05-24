class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int max_visited = 0;
        
        // Try starting from every possible index to find the absolute maximum
        for (int i = 0; i < n; ++i) {
            max_visited = max(max_visited, dfs(i, arr, d, dp));
        }
        
        return max_visited;
    }
    
private:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        // If already calculated, return the memoized result
        if (dp[i] != -1) return dp[i];
        
        int n = arr.size();
        int max_steps = 1; // You can always at least visit the starting index
        
        // 1. Look Right
        for (int x = 1; x <= d && i + x < n; ++x) {
            if (arr[i + x] >= arr[i]) break; // Blocked! Can't jump over or onto this
            max_steps = max(max_steps, 1 + dfs(i + x, arr, d, dp));
        }
        
        // 2. Look Left
        for (int x = 1; x <= d && i - x >= 0; ++x) {
            if (arr[i - x] >= arr[i]) break; // Blocked! Can't jump over or onto this
            max_steps = max(max_steps, 1 + dfs(i - x, arr, d, dp));
        }
        
        return dp[i] = max_steps;
    }
};