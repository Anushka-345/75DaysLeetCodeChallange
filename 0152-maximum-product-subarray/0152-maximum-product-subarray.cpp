class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        int minPro = nums[0];
        int result = nums[0];
        for(int i = 1 ; i< nums.size();i++){
            int Temp = maxPro;
            maxPro = max({nums[i], maxPro*nums[i] , minPro*nums[i]});
            minPro = min({nums[i], Temp*nums[i],minPro*nums[i]});
            result = max(result,maxPro);
        }
        return result;

    }
};