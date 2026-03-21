import sys

# Increase recursion depth for deep trees
sys.setrecursionlimit(200000)

class Solution(object):
    def minEdgeReversals(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in range(n)]
        for u, v in edges:
            # (neighbor, cost_to_move_to_neighbor)
            # 0 means original direction, 1 means needs reversal
            adj[u].append((v, 0))
            adj[v].append((u, 1))
        
        results = [0] * n
        
        # Step 1: Calculate result for root 0
        def dfs_init(u, p):
            total_reversals = 0
            for v, cost in adj[u]:
                if v != p:
                    total_reversals += cost + dfs_init(v, u)
            return total_reversals
        
        results[0] = dfs_init(0, -1)
        
        # Step 2: Re-rooting DFS to calculate all other nodes
        def dfs_reroot(u, p):
            for v, cost in adj[u]:
                if v != p:
                    # If cost was 0 (u->v), moving root to v increases cost by 1
                    # If cost was 1 (v->u), moving root to v decreases cost by 1
                    results[v] = results[u] + (1 if cost == 0 else -1)
                    dfs_reroot(v, u)
        
        dfs_reroot(0, -1)
        return results