#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int minDeletions(std::string s) {
        std::unordered_map<char, int> mp;
        // Fix: Changed loop variable name to 'c' to avoid hiding 's'
        for(char c : s){
            mp[c]++;
        }
        
        std::unordered_set<int> freq;
        int del = 0;
        
        for(auto it : mp){
            int current_freq = it.second;
            
            // Fix: Changed 'if' to 'while' to handle cascading duplicates
            while(current_freq > 0 && freq.count(current_freq)){
                del++;
                current_freq--;
            }
            
            if(current_freq > 0){
               freq.insert(current_freq);
            }
        }
        return del;
    }
};