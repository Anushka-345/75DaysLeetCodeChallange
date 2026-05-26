class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> visited(10001, false);
        int max_score = 0;
        int current_sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (visited[nums[right]]) {
                visited[nums[left]] = false;
                current_sum -= nums[left];
                left++;
            }
            visited[nums[right]] = true;
            current_sum += nums[right];
            max_score = max(max_score, current_sum);
        }

        return max_score;
    }
};