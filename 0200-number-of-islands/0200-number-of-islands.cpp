class Solution {
public:
    vector<vector<bool>> vis;
    int n, m;
    int numIslands(vector<vector<char>>& g) {
        n=g.size(), m=g[0].size();
        int count=0;
        vis=vector<vector<bool>>(n, vector<bool>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (g[i][j]=='1' && !vis[i][j]) {
                    dfs(g, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& g, int i, int j) {
        if (i<0 || j<0 || i>=n || j>=m || g[i][j]=='0' || vis[i][j]) return;
        vis[i][j]=1;
        dfs(g, i-1, j), dfs(g, i+1, j), dfs(g, i, j-1), dfs(g, i, j+1);
    }
};
