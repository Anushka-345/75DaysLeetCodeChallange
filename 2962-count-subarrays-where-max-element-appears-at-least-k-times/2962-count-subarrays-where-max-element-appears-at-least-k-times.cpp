class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long mx = 0 ;
        for(int num : nums){
            mx = max(mx, (long long)num);
        }
        long long left = 0 ;
        long long count = 0 ;
        long long ans = 0 ;
        for(int right = 0 ; right < nums.size() ; right++ ){
            if(nums[right]== mx){
                count++;
            }
            while(count >= k){
                        ans += (nums.size() - right);


                if(nums[left] == mx){
                    count--;
                }
                left++;
            }

        }
        return ans;
    
    }
};