class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;  // pick a new candidate
            }
            if (num == candidate) {
                count++;          // support for candidate
            } else {
                count--;          // decrease count for others
            }
        }

        return candidate; // guaranteed to be majority
    }
};