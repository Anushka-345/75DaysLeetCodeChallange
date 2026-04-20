#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid is greater than right, min is in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // If mid is less than right, min is in left half (including mid)
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            // duplicates case
            else {
                right--;
            }
        }

        return nums[left];
    }
};