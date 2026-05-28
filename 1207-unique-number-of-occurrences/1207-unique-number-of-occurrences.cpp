#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        // Count frequencies of each number
        for (int x : arr) {
            mp[x]++;
        }
        
        unordered_set<int> st;
        // Check if any frequency is repeated
        for (auto& it : mp) {
            if (st.count(it.second)) {
                return false; // Frequency already seen
            }
            st.insert(it.second);
        }
        
        return true; // All frequencies are unique
    }
};