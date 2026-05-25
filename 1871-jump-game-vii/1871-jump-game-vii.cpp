class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        // If the last character is '1', we can never reach it.
        if (s[n - 1] == '1') return false;

        queue<int> q;
        q.push(0);
        
        // max_reached keeps track of the furthest index we've already considered
        // to avoid redundant checks and nested loops.
        int max_reached = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // If we reached the last index, return true
            if (i == n - 1) return true;

            // The window of valid jumps from the current position `i`
            int start = max(i + minJump, max_reached + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    q.push(j);
                }
            }

            // Update max_reached so the next elements don't re-examine these indices
            max_reached = max(max_reached, i + maxJump);
        }

        return false;
    }
};