#include <vector>
#include <cmath>
#include <climits>

class Solution {
public:
    int findClosestNumber(std::vector<int>& nums) {
        int closest = nums[0]; // Initialize with the first element
        
        for (int num : nums) {
            // Condition 1: Current number is strictly closer to 0
            if (std::abs(num) < std::abs(closest)) {
                closest = num;
            } 
            // Condition 2: Equal distance, but current number is larger
            else if (std::abs(num) == std::abs(closest) && num > closest) {
                closest = num;
            }
        }
        
        return closest;
    }
};