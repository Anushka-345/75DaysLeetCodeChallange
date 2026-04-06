class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN ;
        int total = 0 ;
        int n = nums.size();
        for(int i = 0 ; i<n  ; i++){
            total+= nums[i];
            maxSum= max(maxSum , total);
            if(total<0){
                total = 0 ;
            }

        }
        return maxSum;
        
    }
};