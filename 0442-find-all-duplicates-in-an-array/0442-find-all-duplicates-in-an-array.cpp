#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> result;
        
        for (int num : nums) {
            counts[num]++;
        }
        
        for (auto& pair : counts) {
            if (pair.second == 2) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};