class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly(k) = AtMost(k) - AtMost(k - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int i = 0;
        int count = 0;
        unordered_map<int, int> mp;
        
        for (int j = 0; j < nums.size(); j++) {
            // If this is a new distinct element, decrease k
            if (mp[nums[j]] == 0) {
                k--;
            }
            mp[nums[j]]++;
            
            // If we have more than k distinct elements, shrink from the left
            while (k < 0) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    k++;
                }
                i++;
            }
            
            // Key formula: The number of subarrays ending at 'j' 
            // with AT MOST k distinct elements is equal to the window size.
            count += (j - i + 1);
        }
        
        return count;
    }
};