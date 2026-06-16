#include <string>
#include <algorithm>

class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char ch : s) {
            if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (ch == '#') {
                result += result;
            } else if (ch == '%') {
                std::reverse(result.begin(), result.end());
            } else {
                // It's a lowercase English letter
                result.push_back(ch);
            }
        }
        
        return result;
    }
};