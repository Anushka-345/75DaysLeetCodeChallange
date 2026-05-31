class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0; // Tracks the largest element
        int max2 = 0; // Tracks the second largest element
        
        for (int num : nums) {
            if (num > max1) {
                max2 = max1; // Previous largest becomes second largest
                max1 = num;  // Update largest
            } else if (num > max2) {
                max2 = num;  // Update second largest
            }
        }
        
        return (max1 - 1) * (max2 - 1);
    }
};