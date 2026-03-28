class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeroCount = 0, maxLen = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeroCount++;  // count zeros in current window

        // Shrink window if zeros exceed k
        while (zeroCount > k) {
            if (nums[left] == 0) zeroCount--;
            left++;
        }

        // Update max length of window
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
    
    }
};