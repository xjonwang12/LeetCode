class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size(), m=land[0].size();
        visited=vector<vector<bool>>(n, vector<bool>(m, 0));
        vector<vector<int>> ans;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (land[i][j] && !visited[i][j]) {
                    int c=i, d=j;
                    while (d<m && land[i][d]) visited[i][d++]=1;
                    while (c<n && land[c][j]) visited[c++][j]=1;
                    for (int g=i+1; g<c; g++) {
                        for (int h=j+1; h<d; h++) visited[g][h]=1;
                    }
                    ans.push_back({i, j, c-1, d-1});
                }
            }
        }
        return ans;
    }
};