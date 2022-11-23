class Solution {
public:
    int n;
    vector<short> vis;
    vector<vector<int>> g;
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        g=graph;
        vis=vector<short>(n, 0);
        for (int i=0; i<n; i++) {
            if (!vis[i] && !dfs(i, -1)) return false;
        }
        return true;
    }
    
    bool dfs(int c, int l) {
        vis[c]=-l;
        for (auto u : g[c]) {
            if (vis[u]==vis[c]) return false;
            if (!vis[u] && !dfs(u, vis[c])) return false;
        }
        return true;
    }
};