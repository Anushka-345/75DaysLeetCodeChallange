class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // Step 1: Insert all possible prefixes of numbers in arr1 into the hash set
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10; // Chop off the last digit to get the next prefix
            }
        }
        
        int maxLength = 0;
        
        // Step 2: Check all possible prefixes of numbers in arr2
        for (int num : arr2) {
            while (num > 0) {
                // If the current prefix exists in our set, evaluate its length
                if (prefixes.count(num)) {
                    int currentLength = to_string(num).length();
                    maxLength = max(maxLength, currentLength);
                    
                    // Optimization: Smaller prefixes of this specific number 
                    // won't give a larger length, so we can break early.
                    break; 
                }
                num /= 10;
            }
        }
        
        return maxLength;
    }
};