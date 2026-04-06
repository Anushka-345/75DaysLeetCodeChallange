class Solution {
public:
    int findMin(vector<int>& nums) {
          int start = 0;
        int right = nums.size() - 1;
        
        while (start < right) {
            int mid = start + (right - start) / 2;
            
            if (nums[mid] > nums[right]) {
                start = mid + 1;   // minimum is on right side
            } 
            else {
                right = mid;       // minimum is at mid or left side
            }
        }
        
        return nums[start];
    }
};