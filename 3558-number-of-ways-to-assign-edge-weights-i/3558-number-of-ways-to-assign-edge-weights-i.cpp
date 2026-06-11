#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function for modular exponentiation: (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        // Build the adjacency list for the tree
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS to find the maximum depth (number of edges from root)
        queue<pair<int, int>> q; // {node, current_depth}
        vector<bool> visited(n + 1, false);
        
        q.push({1, 0});
        visited[1] = true;
        
        int max_depth = 0;
        
        while (!q.empty()) {
            auto [u, depth] = q.front();
            q.pop();
            
            max_depth = max(max_depth, depth);
            
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, depth + 1});
                }
            }
        }

        // If max_depth is k, the answer is 2^(k-1) % MOD
        return power(2, max_depth - 1);
    }
};