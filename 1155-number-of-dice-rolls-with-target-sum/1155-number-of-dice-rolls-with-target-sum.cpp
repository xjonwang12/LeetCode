class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        if (n*k<t || n>t) return 0;
        if (n*k==t || n==t) return 1;
        vector<vector<int>> dp(n, vector<int>(t, 0));
        int m=min(k, t);
        for (int i=0; i<m; i++) {
            dp[0][i]=1;
        }
        for (int i=1; i<n; i++) {
            m=min(k*i+k, t);
            for (int j=i; j<m; j++) {
                for (int h=1; h<=k; h++) {
                    if (j-h<0) break;
                    dp[i][j]+=dp[i-1][j-h];
                    dp[i][j] %= (int) 1e9 + 7;
                }
            }
        }
        /*
        for (auto v:dp) {
            for (auto x:v) {
                cout << x << " ";
            }
            cout << endl;
        }
        */
        return dp[n-1][t-1];
    }
};