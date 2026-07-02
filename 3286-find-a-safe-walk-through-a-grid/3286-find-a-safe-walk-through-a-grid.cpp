#include <vector>
#include <deque>
#include <tuple>

class Solution {
public:
    bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Min cost to reach each cell
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, 1e9));
        std::deque<std::pair<int, int>> dq;
        
        int startCost = grid[0][0];
        if (startCost >= health) return false;
        
        dist[0][0] = startCost;
        dq.push_back({0, 0});
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newCost = dist[r][c] + grid[nr][nc];
                    if (newCost < health && newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        if (grid[nr][nc] == 0) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1] < health;
    }
};