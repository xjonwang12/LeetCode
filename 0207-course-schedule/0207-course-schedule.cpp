class Solution {
public:
    int i;
    vector<vector<int>> g;
    vector<short> vis;
    bool canFinish(int n, vector<vector<int>>& p) {
        g.resize(n), vis.resize(n, 0);
        for (auto e : p) {
            g[e[1]].push_back(e[0]);
        }
        for (i=0; i<n; i++) {
            if (!vis[i] && g[i].size()) {
                if (dfs(i)) return false;
            }
        }
        return true;
    }
    
    bool dfs(int u) {
        vis[u]=1;
        for (auto v : g[u]) {
            cout << u << " " << v << endl;
            if (vis[v]==1) return true;
            if (vis[v]!=2 && dfs(v)) return true;
        }
        vis[u]=2;
        return false;
    }
};