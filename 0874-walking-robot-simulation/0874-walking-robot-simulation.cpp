#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obsSet;
        for(auto &obs : obstacles) {
            obsSet.insert({obs[0], obs[1]});
        }
        
        // Directions: N, E, S, W
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;
        
        for(int cmd : commands) {
            if(cmd == -2) {          // turn left
                dir = (dir + 3) % 4;
            } else if(cmd == -1) {   // turn right
                dir = (dir + 1) % 4;
            } else {
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(obsSet.count({nx, ny})) break;  // hit obstacle
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};