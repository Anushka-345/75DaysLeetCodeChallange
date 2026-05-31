class Solution {
private:
    // Helper function to reverse a non-negative integer
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

public:
    int countNicePairs(vector<int>& nums) {
        long long nicePairs = 0;
        int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        
        for (int num : nums) {
            // Transform the condition: nums[i] - rev(nums[i])
            int key = num - reverseNum(num);
            
            // If we've seen this transformed key before, add its frequency to our total
            if (mp.find(key) != mp.end()) {
                nicePairs = (nicePairs + mp[key]) % MOD;
            }
            
            // Increment the frequency of the key in the map
            mp[key]++;
        }
        
        return nicePairs;
    }
};