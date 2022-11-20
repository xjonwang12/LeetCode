class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        if (s==d) return true;
        vector<vector<int>> g(n, vector<int>());
        for (auto edge : e) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, 0);
        return dfs(g, visited, s, d);
    }
    
    bool dfs(vector<vector<int>>& g, vector<bool>& visited, int s, int d) {
        visited[s]=1;
        for (auto v : g[s]) {
            if (v==d) return true;
            if (!visited[v] && dfs(g, visited, v, d)) return true;
        }
        return false;
    }
};