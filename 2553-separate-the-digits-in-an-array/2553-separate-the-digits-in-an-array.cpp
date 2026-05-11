class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int val : nums) {
            string s = to_string(val);
            for (char c : s) {
                answer.push_back(c - '0'); // Convert char back to int
            }
        }
        return answer;
    }
};