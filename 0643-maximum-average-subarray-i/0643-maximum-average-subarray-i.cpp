class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       double windowSum = 0 ;
       for(int i =  0 ; i <k ; i++){
        windowSum += nums[i];
       }
       double maxsum = windowSum;
       for(int i = k ; i < nums.size() ; i++){
         windowSum = windowSum + nums[i]- nums[i-k];
         maxsum = max(maxsum , windowSum);
       }
       return (double) maxsum/k;
    }
};