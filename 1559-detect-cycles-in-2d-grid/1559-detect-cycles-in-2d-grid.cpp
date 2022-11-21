class Solution {
    int n,m;
    bool vis[505][505];
    bool cycle=false;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<char>> g;
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = grid;
        memset(vis, false, sizeof(vis));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j]) if (dfs(i,j,-1,-1)) return true;
            }
        }
        return false;
    }

    bool dfs(int ux, int uy, int lx, int ly)
    {
        vis[ux][uy]=true;
        for(int i=0; i<4; i++) {
            int vx=ux+dx[i], vy=uy+dy[i];
            if(vx==lx && vy==ly) continue;
            if(vx>=0 && vy>=0 && vx<n && vy<m && g[vx][vy]==g[ux][uy]){
                if(vis[vx][vy] || dfs(vx, vy, ux, uy)) return true;
            }  
        }
        return false;
    }
};