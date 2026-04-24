class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "..") {
                    if (!stack.empty()) stack.pop_back();
                } else if (!curr.empty() && curr != ".") {
                    stack.push_back(curr);
                }
                curr = "";
            } else {
                curr += path[i];
            }
        }

        // Build result
        string result = "";
        for (auto &dir : stack) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};