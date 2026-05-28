#include <vector>
#include <algorithm>

class Solution {
public:
    int waysToSplit(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefix(n, 0);
        
        // 1. Calculate prefix sums
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        int totalWays = 0;
        int MOD = 1e9 + 7;
        
        // 2. Loop through possible ends for the 'left' subarray
        // We stop at n - 3 because 'mid' and 'right' need at least 1 element each
        for (int i = 0; i < n - 2; i++) {
            int leftSum = prefix[i];
            
            // The minimum sum prefix[j] must reach
            int minMidPrefix = 2 * leftSum; 
            // The maximum sum prefix[j] can reach
            int maxMidPrefix = leftSum + (prefix[n - 1] - leftSum) / 2;
            
            if (minMidPrefix > maxMidPrefix) continue; // No valid split possible for this i
            
            // Search range for 'j' must be strictly between index i+1 and n-2
            auto start_search = prefix.begin() + i + 1;
            auto end_search = prefix.begin() + n - 1;
            
            // Binary search for the first valid j index
            auto left_bound = std::lower_bound(start_search, end_search, minMidPrefix);
            
            // Binary search for the first index strictly greater than the max allowed value
            auto right_bound = std::upper_bound(start_search, end_search, maxMidPrefix);
            
            // If valid positions exist, add the count of indices between them
            if (left_bound < right_bound) {
                totalWays = (totalWays + (right_bound - left_bound)) % MOD;
            }
        }
        
        return totalWays;
    }
};