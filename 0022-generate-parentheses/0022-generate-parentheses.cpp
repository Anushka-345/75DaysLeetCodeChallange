class Solution {
public:
    void backtrack(vector<string>& res, string current, int open, int close, int n) {
        if(current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        
        if(open < n) 
            backtrack(res, current + '(', open + 1, close, n);
        
        if(close < open) 
            backtrack(res, current + ')', open, close + 1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};