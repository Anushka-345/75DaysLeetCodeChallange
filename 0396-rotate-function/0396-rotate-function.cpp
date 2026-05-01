class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long totalSum = 0;
        long long currentF = 0;
        
        // 1. Calculate the initial F(0) and the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            currentF += (long long)i * nums[i];
        }
        
        long long maxF = currentF;
        
        // 2. Use the derived formula to find F(1)...F(n-1) in O(1) each
        // F(k) = F(k-1) + totalSum - n * nums[n-k]
        for (int i = 1; i < n; i++) {
            currentF = currentF + totalSum - n * nums[n - i];
            maxF = max(maxF, currentF);
        }
        
        return (int)maxF;
    }
};