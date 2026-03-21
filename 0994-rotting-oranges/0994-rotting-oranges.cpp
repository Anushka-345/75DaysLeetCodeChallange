class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: Initialize the queue with rotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        if(fresh == 0) return 0; // no fresh oranges
        
        int minutes = 0;
        vector<int> dirX = {0,0,1,-1};
        vector<int> dirY = {1,-1,0,0};
        
        // Step 2: BFS
        while(!q.empty()) {
            int sz = q.size();
            bool rotted_this_minute = false;
            
            for(int i = 0; i < sz; i++) {
                auto [x,y] = q.front(); q.pop();
                
                for(int d = 0; d < 4; d++) {
                    int nx = x + dirX[d];
                    int ny = y + dirY[d];
                    
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // rot the fresh orange
                        q.push({nx,ny});
                        fresh--;
                        rotted_this_minute = true;
                    }
                }
            }
            
            if(rotted_this_minute) minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};