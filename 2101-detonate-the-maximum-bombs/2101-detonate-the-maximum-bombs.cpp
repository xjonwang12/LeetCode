class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> adj;
    int maximumDetonation(vector<vector<int>>& b) {
        int a=0;
        adj.resize(b.size());
        vis.resize(b.size(), 0);
        for (int i=0; i<b.size(); i++) {
            for (int j=0; j<b.size(); j++) {
                if (i==j) continue;
                if (pow(b[j][0]-b[i][0], 2) + pow(b[j][1]-b[i][1], 2) <= pow(b[i][2], 2)) adj[i].push_back(j);
            }
        }
        for (int i=0; i<b.size(); i++) {
            if (!vis[i]) {
                int c=0;
                vector<bool> visited(b.size(), 0);
                dfs(i, c, visited);
                a=max(a, c);
            }
        }
        return a;
    }
    
    void dfs(int s, int& c, vector<bool>& visited) {
        c++;
        vis[s]=1, visited[s]=1;
        for (auto u : adj[s]) {
            if (!visited[u]) dfs(u, c, visited);
        }
    }
};