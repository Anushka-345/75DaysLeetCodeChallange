class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0 ;
        int j = nums.size()-1;
        int k = nums.size()-1;
        vector<int> ans (nums.size());
        while(k >= 0){
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j]; 
            if( a > b){
                ans[k] = a ;
                i++;
            }
            else{
                ans[k] = b ;
                j--;
            }
            k--;
        }
        return ans;
    }
};