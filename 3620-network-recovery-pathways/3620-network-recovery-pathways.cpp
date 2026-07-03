#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int max_edge_cost = 0;
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            max_edge_cost = max(max_edge_cost, edge[2]);
        }
        
        int low = 0, high = max_edge_cost;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReach(n, adj, online, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
private:
    bool canReach(int n, const vector<vector<pair<int, int>>>& adj, const vector<bool>& online, long long k, int min_cost) {
        // Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, -1);
        
        // Start node must be online (problem guarantees 0 and n-1 are online)
        pq.push({0, 0});
        dist[0] = 0;
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u] && dist[u] != -1) continue;
            if (u == n - 1) return true;
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int cost = edge.second;
                
                // Only consider edges with cost >= min_cost and online nodes
                if (cost >= min_cost && online[v]) {
                    if (dist[v] == -1 || dist[u] + cost < dist[v]) {
                        if (dist[u] + cost <= k) {
                            dist[v] = dist[u] + cost;
                            pq.push({dist[v], v});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};