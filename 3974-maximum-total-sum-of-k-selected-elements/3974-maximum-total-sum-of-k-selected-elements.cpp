#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        // Sort in descending order to easily pick the largest elements
        sort(nums.rbegin(), nums.rend());
        
        long long totalSum = 0;
        
        // We will process the k largest elements
        for (int i = 0; i < k; ++i) {
            // If mul > 1, it's always beneficial to multiply
            if (mul > 1) {
                totalSum += (long long)nums[i] * mul;
            } else {
                // Otherwise, just add the element
                totalSum += nums[i];
            }
            // Decrease mul after each step
            mul--;
        }
        
        return totalSum;
    }
};