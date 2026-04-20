#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        // Case 1: fix first house (0)
        int j = n - 1;
        while (j > 0 && colors[j] == colors[0]) {
            j--;
        }
        int dist1 = j;  // distance from 0 to j

        // Case 2: fix last house (n-1)
        int i = 0;
        while (i < n - 1 && colors[i] == colors[n - 1]) {
            i++;
        }
        int dist2 = (n - 1) - i;

        return max(dist1, dist2);
    }
};