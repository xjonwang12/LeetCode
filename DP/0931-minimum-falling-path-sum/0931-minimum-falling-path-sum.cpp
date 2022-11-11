class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> best(n, vector<int>(n));
        for (int i=0; i<n;i++) best[0][i] = matrix[0][i];
        for (int j=1; j<n;j++) {
            for (int k=0; k<n;k++) {
                int parent=(k>0 && best[j-1][k-1]<best[j-1][k]) ? best[j-1][k-1] : best[j-1][k];
                parent=(k<n-1 && best[j-1][k+1]<parent) ? best[j-1][k+1] : parent;
                best[j][k]=parent + matrix[j][k];
            }
        }
        int ans=INT_MAX;
        for (int i=0; i<n;i++) ans=(best[n-1][i]<ans) ? best[n-1][i] : ans;
        return ans;
    }
};