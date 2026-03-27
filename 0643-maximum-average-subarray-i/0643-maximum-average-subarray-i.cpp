class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 ;
        int n = nums.size();
        for(int i = 0 ; i < k ; i++){
            sum+= nums[i];
        }
        double window = sum;
        for(int i = k ; i < n ; i++ ){
             sum = sum - nums[i-k]+nums[i];
             window = max(window , sum);
        }
        return window/k;
    }
};