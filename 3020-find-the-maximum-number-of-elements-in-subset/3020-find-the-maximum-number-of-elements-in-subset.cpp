#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int max_len = 0;
        
        // 1. Handle the special case for 1s
        if (count.count(1)) {
            int num_ones = count[1];
            max_len = (num_ones % 2 == 0) ? num_ones - 1 : num_ones;
        }
        
        // 2. Check for all other bases x > 1
        for (auto& [x, freq] : count) {
            if (x == 1) continue;
            
            int current_len = 0;
            long long current_base = x;
            
            // Step up the power chain while we have at least 2 duplicates
            while (count.count(current_base) && count[current_base] >= 2) {
                current_len += 2;
                current_base = current_base * current_base; // square the base
            }
            
            // Check if the next element can be the peak
            if (count.count(current_base) && count[current_base] >= 1) {
                current_len += 1;
            } else {
                current_len -= 1; // Reclaim one element from the last pair to act as peak
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};