class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nums(n);
        for(int i = 0; i < n; ++i) sorted_nums[i] = {nums[i], i};
        sort(sorted_nums.begin(), sorted_nums.end());

        vector<int> pos(n); // original index to sorted position
        for(int i = 0; i < n; ++i) pos[sorted_nums[i].second] = i;

        // Group components
        vector<int> comp(n);
        int c = 0;
        comp[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(sorted_nums[i].first - sorted_nums[i-1].first > maxDiff) c++;
            comp[i] = c;
        }

        // Build Sparse Table
        int max_log = log2(n) + 1;
        vector<vector<int>> up(max_log, vector<int>(n));
        int right = 0;
        for(int i = 0; i < n; ++i) {
            while(right < n && sorted_nums[right].first <= sorted_nums[i].first + maxDiff) right++;
            up[0][i] = right - 1;
        }

        for(int k = 1; k < max_log; ++k) {
            for(int i = 0; i < n; ++i) {
                up[k][i] = up[k-1][up[k-1][i]];
            }
        }

        vector<int> results;
        for(auto& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if(u > v) swap(u, v);
            if(comp[u] != comp[v]) {
                results.push_back(q[0] == q[1] ? 0 : -1);
            } else if(u == v) {
                results.push_back(0);
            } else {
                int dist = 0;
                int curr = u;
                for(int k = max_log - 1; k >= 0; --k) {
                    if(up[k][curr] < v) {
                        curr = up[k][curr];
                        dist += (1 << k);
                    }
                }
                results.push_back(dist + 1);
            }
        }
        return results;
    }
};