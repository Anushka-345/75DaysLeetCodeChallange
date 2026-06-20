#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Push the base restriction for building 1
        restrictions.push_back({1, 0});
        
        // Sort restrictions by building ID
        sort(restrictions.begin(), restrictions.end());
        
        // If the last building n is not explicitly restricted, add a loose boundary for it
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        
        int m = restrictions.size();
        
        // Pass 1: Left to Right propagation
        for (int i = 1; i < m; ++i) {
            int id_diff = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + id_diff);
        }
        
        // Pass 2: Right to Left propagation
        for (int i = m - 2; i >= 0; --i) {
            int id_diff = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + id_diff);
        }
        
        // Find the absolute maximum height achieved at any peak between restrictions
        int max_ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int l = restrictions[i][0], r = restrictions[i+1][0];
            int h1 = restrictions[i][1], h2 = restrictions[i+1][1];
            
            // Formula to find the max peak height between two restricted points
            int peak = (h1 + h2 + (r - l)) / 2;
            max_ans = max(max_ans, peak);
        }
        
        return max_ans;
    }
};