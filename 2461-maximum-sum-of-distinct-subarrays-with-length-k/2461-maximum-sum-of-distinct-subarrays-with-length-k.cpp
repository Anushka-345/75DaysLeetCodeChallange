class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         int n = nums.size();
        set<int> s;
        long long curr = 0;
        long long maxSum = 0;  // change to long long
        int left = 0;

        for(int right = 0 ; right< n  ; right++){
            while(s.count(nums[right])|| s.size()==k){
                s.erase(nums[left]);
                curr -= nums[left];
                left++;
            }
            
            curr+= nums[right];
            s.insert(nums[right]);

    
            if(s.size()==k){
                maxSum = max(maxSum,curr);
            }


        }
        return maxSum;
    }
};