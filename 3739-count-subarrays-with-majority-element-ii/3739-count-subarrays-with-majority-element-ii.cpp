class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Frequency array to store counts of each prefix sum.
        // Size is 2*n + 1 to handle range [-n, n] using an index offset of 'n'.
        vector<int> freq(2 * n + 1, 0);
        
        int prefix_sum = 0;
        freq[0 + n] = 1; // Base case: prefix sum of 0 occurs once initially
        
        long long total_subarrays = 0;
        long long valid_prev_counts = 0; 
        
        for (int x : nums) {
            if (x == target) {
                // Moving +1 means everything previously smaller than 'prefix_sum' 
                // AND 'prefix_sum' itself are now strictly smaller than the new prefix sum.
                valid_prev_counts += freq[prefix_sum + n];
                prefix_sum++;
            } else {
                // Moving -1 means the prefix sum drops. The elements that were 
                // equal to the NEW prefix sum are no longer smaller than it.
                prefix_sum--;
                valid_prev_counts -= freq[prefix_sum + n];
            }
            
            total_subarrays += valid_prev_counts;
            freq[prefix_sum + n]++;
        }
        
        return total_subarrays;
    }
};