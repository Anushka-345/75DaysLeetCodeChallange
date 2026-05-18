#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Step 1: Map each value to all its indices
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; i++) {
            valueToIndices[arr[i]].push_back(i);
        }

        // Step 2: Initialize BFS queue and visited array
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        int steps = 0;

        // Step 3: Standard BFS loop
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                // Target reached
                if (curr == n - 1) return steps;

                // Option 1: Jump to curr + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Option 2: Jump to curr - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Option 3: Jump to any index with the same value
                if (valueToIndices.count(arr[curr])) {
                    for (int nextIdx : valueToIndices[arr[curr]]) {
                        if (!visited[nextIdx]) {
                            visited[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                    // Crucial Optimization: Clear the entry so we don't traverse it again
                    valueToIndices.erase(arr[curr]);
                }
            }
            steps++;
        }

        return -1;
    }
};