class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0 ;
        int mn = INT_MAX;
        int sum = 0 ;
        for( int j = 0 ; j < nums.size(); j++){
            sum += nums[j];
            while( sum >= target){
                mn = min(mn , j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return mn == INT_MAX ? 0 : mn ;
    }
};