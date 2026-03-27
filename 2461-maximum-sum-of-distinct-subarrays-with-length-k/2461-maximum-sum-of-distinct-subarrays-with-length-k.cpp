class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        set<int>s;
        long long maxSum = 0 ;
        long long curr = 0;
        int left = 0 ;
        for(int right = 0 ; right < n ; right++){
            while(s.count(nums[right]) || s.size()==k){
                curr -= nums[left];
                s.erase(nums[left]);
                left++;
            }
            curr += nums[right];
            s.insert(nums[right]);
            if(s.size()==k){
                maxSum = max(maxSum,curr);
            }
        }
        return maxSum;
    }
};