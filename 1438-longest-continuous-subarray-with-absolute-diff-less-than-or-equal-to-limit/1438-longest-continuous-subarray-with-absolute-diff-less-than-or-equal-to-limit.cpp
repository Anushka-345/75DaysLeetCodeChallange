#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> max_deque;
        std::deque<int> min_deque;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Maintain decreasing order in max_deque
            while (!max_deque.empty() && max_deque.back() < nums[right]) {
                max_deque.pop_back();
            }
            max_deque.push_back(nums[right]);

            // Maintain increasing order in min_deque
            while (!min_deque.empty() && min_deque.back() > nums[right]) {
                min_deque.pop_back();
            }
            min_deque.push_back(nums[right]);

            // If the current window violates the condition, shrink it from the left
            while (max_deque.front() - min_deque.front() > limit) {
                if (max_deque.front() == nums[left]) {
                    max_deque.pop_front();
                }
                if (min_deque.front() == nums[left]) {
                    min_deque.pop_front();
                }
                left++; // Shrink window
            }

            // Update the maximum length found so far
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};