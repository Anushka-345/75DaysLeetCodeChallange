class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // key: sorted string, value: group
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sort the string
            mp[key].push_back(s); // add original string to the group
        }
        
        vector<vector<string>> result;
        for (auto &p : mp) {
            result.push_back(p.second); // push each group into result
        }
        return result;
    }
};