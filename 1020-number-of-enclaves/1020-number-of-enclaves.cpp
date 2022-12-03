class Solution {
public:
    int n, m, a=0;
    void dfs(vector<vector<int>>& g, int i, int j, int& c, bool& b) {
        if (i<0 || j<0 || i>=n || j>=m) {
            b=1;
            return;
        }
        if (!g[i][j]) return;
        c++, g[i][j]=0;
        dfs(g, i+1, j, c, b), dfs(g, i-1, j, c, b), dfs(g, i, j+1, c, b), dfs(g, i, j-1, c, b);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int c=0;
                bool b=0;
                if (grid[i][j]) dfs(grid, i, j, c, b);
                a += !b ? c : 0;
            }
        }
        return a;
    }
};