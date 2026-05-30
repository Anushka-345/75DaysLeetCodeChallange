#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Max limit of x based on constraints
        int M = max_x + 1;
        SegmentTree st(M);
        
        // Set to store obstacle coordinates dynamically
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(M); // Sentinel boundary
        
        vector<bool> results;
        
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);
                
                // Update segment tree values
                st.update(1, 0, M, x, x - prev_obs);
                if (next_obs != M) {
                    st.update(1, 0, M, next_obs, next_obs - x);
                }
                
                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obstacles.upper_bound(x);
                int prev_obs = *prev(it);
                
                // Maximum gap completely inside [0, prev_obs]
                int max_gap = st.query(1, 0, M, 0, prev_obs);
                
                // Check if internal gap is enough or the tail space is enough
                if (max_gap >= sz || (x - prev_obs) >= sz) {
                    results.push_back(true);
                } else {
                    results.push_back(false);
                }
            }
        }
        
        return results;
    }
};