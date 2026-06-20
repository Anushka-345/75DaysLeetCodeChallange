class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        // prefix[i] will store the sum of the first i elements
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            // The sum of elements from nums[start] to nums[i] 
            // is calculated via prefix[i + 1] - prefix[start]
            totalSum += (prefix[i + 1] - prefix[start]);
        }
        
        return totalSum;
    }
};