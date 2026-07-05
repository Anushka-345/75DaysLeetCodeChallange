#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // 1. Find the target number of distinct elements
        unordered_set<int> distinct_elements(nums.begin(), nums.end());
        int target = distinct_elements.size();
        
        int n = nums.size();
        unordered_map<int, int> window_freq; // Using hash map for O(1) average access
        int left = 0;
        int count = 0;
        
        // 2. Sliding window traversal
        for (int right = 0; right < n; ++right) {
            window_freq[nums[right]]++;
            
            // While the current window is "complete"
            while (window_freq.size() == target) {
                // If valid, all subarrays ending at current 'right' and beyond are complete
                count += (n - right);
                
                // Shrink from the left to find other valid subarrays
                window_freq[nums[left]]--;
                if (window_freq[nums[left]] == 0) {
                    window_freq.erase(nums[left]);
                }
                left++;
            }
        }
        
        return count;
    }
};