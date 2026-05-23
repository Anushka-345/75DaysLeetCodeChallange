#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    long long countExcellentPairs(std::vector<int>& nums, int k) {
        // Step 1: Remove duplicate numbers
        std::unordered_set<int> unique_nums(nums.begin(), nums.end());
        
        // Step 2: Extract the set bit counts
        std::vector<int> bits;
        bits.reserve(unique_nums.size());
        for (int num : unique_nums) {
            bits.push_back(__builtin_popcount(num));
        }
        
        // Step 3: Sort the bit counts to apply the two-pointer technique
        std::sort(bits.begin(), bits.end());
        
        long long excellent_pairs = 0;
        int left = 0;
        int right = bits.size() - 1;
        
        // Step 4: Two-pointer approach for distinct elements (A != B)
        while (left < right) {
            if (bits[left] + bits[right] >= k) {
                // All elements from index 'left' to 'right - 1' can pair validly with 'right'
                excellent_pairs += (right - left);
                right--; // Move the right pointer inward
            } else {
                left++;  // Sum is too small, make the left element larger
            }
        }
        
        // Since (a, b) and (b, a) are distinct pairs, multiply by 2
        excellent_pairs *= 2;
        
        // Step 5: Include self-pairing cases (a, a) where popcount(a) + popcount(a) >= k
        for (int b : bits) {
            if (b * 2 >= k) {
                excellent_pairs++;
            }
        }
        
        return excellent_pairs;
    }
};