class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size(), m=o[0].size();
        vector<int> dp1(m, 0), dp2(m, 0);
        for (int i=0; i<m; i++) {
            if (o[0][i]) break;
            dp1[i]++;
        }
        for (int i=1; i<n; i++) {
            if (!o[i][0]) dp2[0]+=dp1[0];
            for (int j=1; j<m; j++) {
                if (o[i][j]) continue;
                dp2[j]+=dp2[j-1]+dp1[j];
            }
            dp1=dp2;
            dp2=vector<int>(m, 0);
        }
        return dp1[m-1];
    }
};