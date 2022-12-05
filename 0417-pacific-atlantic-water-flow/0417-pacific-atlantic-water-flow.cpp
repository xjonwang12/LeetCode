class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(), m=h[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> a(n, vector<bool>(m, 0)), p=a;
        queue<pair<int, int>> q;
        int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
        
        for (int i=0; i<n; i++) {
            a[i][0]=1;
            q.push({i, 0});
        }
        for (int i=1; i<m; i++) {
            a[0][i]=1;
            q.push({0, i});
        }
        while (!q.empty()) {
            int x=q.front().first, y=q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int tx=x+dx[i], ty=y+dy[i];
                if (tx >= 0 && ty >= 0 && tx < n && ty < m && !a[tx][ty] && h[tx][ty]>=h[x][y]) {
                    a[tx][ty]=1;
                    q.push({tx, ty});
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            p[i][m-1]=1;
            q.push({i, m-1});
        }
        for (int i=0; i<m-1; i++) {
            p[n-1][i]=1;
            q.push({n-1, i});
        }
        while (!q.empty()) {
            int x=q.front().first, y=q.front().second;
            q.pop();
            if (a[x][y]) ans.push_back({x, y});
            for (int i=0; i<4; i++) {
                int tx=x+dx[i], ty=y+dy[i];
                if (tx >= 0 && ty >= 0 && tx < n && ty < m && !p[tx][ty] && h[tx][ty]>=h[x][y]) {
                    p[tx][ty]=1;
                    q.push({tx, ty});
                }
            }
        }
        return ans;
    }
};