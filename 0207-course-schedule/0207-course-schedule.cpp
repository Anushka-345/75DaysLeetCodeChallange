
class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        if(visited[node] == 1) return false; // cycle detected
        if(visited[node] == 2) return true;  // already safe
        
        visited[node] = 1; // mark as visiting
        for(int neighbor : graph[node]) {
            if(!dfs(neighbor, graph, visited)) return false;
        }
        visited[node] = 2; // mark as safe
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            graph[prereq].push_back(course);
        }
        
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(!dfs(i, graph, visited)) return false;
            }
        }
        return true;
    }
};