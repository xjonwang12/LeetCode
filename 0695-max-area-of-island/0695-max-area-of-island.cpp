class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        visited=vector<vector<bool>>(n, vector<bool>(m, 0));
        int b=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int c=0;
                if (!visited[i][j] && grid[i][j]) dfs(grid, i, j, c);
                b=max(b, c);
            }
        }
        return b;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& c) {
        if (i<0 || j<0 || i>=n || j>=m || visited[i][j]) return;
        visited[i][j]=1;
        if (grid[i][j]) dfs(grid, i+1, j, ++c), dfs(grid, i, j+1, c), dfs(grid, i-1, j, c), dfs(grid, i, j-1, c);
    }
};