class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        if (n*k<t || n>t) return 0;
        if (n*k==t || n==t) return 1;
        vector<int> dp(t,0), dp2(t,0);
        int m=min(k, t);
        for (int i=0; i<m; i++) {
            dp[i]=1;
        }
        for (int i=1; i<n; i++) {
            m=min(k*i+k, t);
            for (int j=i; j<m; j++) {
                for (int h=1; h<=k; h++) {
                    if (j-h<0) break;
                    dp2[j]+=dp[j-h];
                    dp2[j] %= (int) 1e9 + 7;
                }
            }
            cout << endl;
            dp=dp2;
            dp2=vector<int>(t, 0);
        }
        
        return dp[t-1];
    }
};