class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Step 1: store robots with position, health, direction, and original index
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Step 2: sort robots by position
        sort(robots.begin(), robots.end());
        
        // Stack for R-moving robots: pair<health, original_index>
        vector<pair<int,int>> stackR;
        vector<pair<int,int>> survived; // pair<health, original_index> for L survivors
        
        for(auto &[pos, health, dirc, idx] : robots) {
            if(dirc == 'R') {
                stackR.push_back({health, idx});
            } else { // dirc == 'L'
                while(!stackR.empty() && health > 0) {
                    auto &[top_health, top_idx] = stackR.back();
                    if(top_health == health) {
                        stackR.pop_back();
                        health = 0;
                    } else if(top_health > health) {
                        stackR.back().first -= 1;
                        health = 0;
                    } else { // top_health < health
                        stackR.pop_back();
                        health -= 1;
                    }
                }
                if(health > 0) {
                    survived.push_back({health, idx});
                }
            }
        }
        
        // Add remaining R robots
        for(auto &[h, idx] : stackR) {
            survived.push_back({h, idx});
        }
        
        // Sort by original index to preserve input order
        sort(survived.begin(), survived.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        
        // Extract healths
        vector<int> result;
        for(auto &[h, idx] : survived) {
            result.push_back(h);
        }
        return result;
    }
};