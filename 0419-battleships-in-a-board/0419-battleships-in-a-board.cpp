class Solution {
public:
    int n, m;
    int countBattleships(vector<vector<char>>& b) {
        int c=0;
        n=b.size(), m=b[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (b[i][j]=='X') dfs(b, i, j), c++;
            }
        }
        return c;
    }
    
    void dfs(vector<vector<char>>& b, int i, int j) {
        if (i<0 || j<0 || i>=n || j>=m || b[i][j]!='X') return;
        dfs(b, i+1, j), dfs(b, i, j+1);
        b[i][j]='x';
    }
};