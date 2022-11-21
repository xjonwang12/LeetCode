class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<bool> vis;
    int count;
    int minReorder(int n, vector<vector<int>>& connections) {
        adj=vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        vis=vector<bool>(n);
        count=0;
        for (auto e : connections) adj[e[0]].push_back({e[1], 0}), adj[e[1]].push_back({e[0], 1});
        dfs(0);
        return n-1-count;
    }
    
    void dfs(int u) {
        vis[u]=1;
        for (auto v : adj[u]) {
            if (!vis[v.first]) {
                if (v.second) count++;
                dfs(v.first);
            }
        }
    }
};