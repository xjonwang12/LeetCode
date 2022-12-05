class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis, a;
    int c=0;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& a) {
        adj.resize(a.size());
        vis.resize(a.size(), 0);
        this->a=a;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0);
        return c;
    }
    
    bool dfs(int u) {
        vis[u]=1;
        bool t=0;
        for (auto v : adj[u]) {
            if (!vis[v] && dfs(v)) c+=2, t=1;
        }
        return t||a[u];
    }
};