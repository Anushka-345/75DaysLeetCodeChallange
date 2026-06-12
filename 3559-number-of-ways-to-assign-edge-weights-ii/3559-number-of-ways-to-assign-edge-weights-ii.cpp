#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<int> pow2;

    void dfs(int node, int p, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = p;
        
        for (int j = 1; j < LOG; ++j) {
            if (up[node][j - 1] != -1) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            } else {
                up[node][j] = -1;
            }
        }

        for (int neighbor : adj[node]) {
            if (neighbor != p) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Bring both nodes to the same depth
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; ++j) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        // Lift both nodes simultaneously
        for (int j = LOG - 1; j >= 0; --j) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;

        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        // 1. Run DFS to structure the tree
        dfs(1, -1, 0, adj);

        // 2. Precompute powers of 2 modulo 10^9 + 7
        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        // 3. Process queries
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];

            // Formula: 2^(k-1)
            ans.push_back(pow2[pathLength - 1]);
        }

        return ans;
    }
};