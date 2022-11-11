class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> c(m, vector<int>(n,0));
        c[0][0]=grid[0][0];
        for (int i=1; i<m; i++) c[i][0]=c[i-1][0]+grid[i][0];
        for (int i=1; i<n; i++) c[0][i]=c[0][i-1]+grid[0][i];
        for (int i=1; i<m; i++) for (int j=1; j<n; j++) c[i][j]=((c[i-1][j]<c[i][j-1])?c[i-1][j]:c[i][j-1]) + grid[i][j];
        return c[m-1][n-1];
    }
};