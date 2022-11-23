class Solution {
public:
    int n;
    vector<short> vis;
    bool isBipartite(vector<vector<int>>& g) {
        n=g.size();
        vis=vector<short>(n, 0);
        for (int i=0; i<n; i++) {
            if (!vis[i] && !dfs(g, i, -1)) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& g, int c, int l) {
        vis[c]=-l;
        for (auto u : g[c]) {
            if (vis[u]==vis[c]) return false;
            if (!vis[u] && !dfs(g, u, vis[c])) return false;
        }
        return true;
    }
};