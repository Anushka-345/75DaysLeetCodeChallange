class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int>s;
        long long curr = 0 ;
        int left = 0 ;
        long long maxSum = 0 ;
        for(int right = 0 ; right< nums.size() ; right++){
           while(s.count(nums[right]) || s.size() >= k){
                s.erase(nums[left]);
                curr -= nums[left];
                left++;
            }
            s.insert(nums[right]);
            curr += nums[right];
            if( s.size() == k){
                maxSum = max(maxSum , curr);
            }

        }
        return maxSum;
    }
};