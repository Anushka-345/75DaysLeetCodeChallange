class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int curr = 0 ;
       int left = 0 ;
       int minLen = INT_MAX;
       for(int right = 0 ; right <nums.size(); right++){
        curr += nums[right];

       
       while( curr >= target  ){
        minLen = min(minLen , right - left + 1);
        curr -= nums[left];
        left++;
       }
       }
       return (minLen == INT_MAX)? 0 : minLen;
       
    }
};