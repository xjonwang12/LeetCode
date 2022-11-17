class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp1(n+1, 0), dp2(n+1, 0);
        dp1[0]=1, dp1[1]=1, dp2[0]=1;
        for (int i=2; i<=n; i++) {
            dp1[i]=(dp1[i-1]+dp1[i-2]+dp2[i-1]) % ((int)1e9+7);
            dp2[i]=(2*dp1[i-2]+dp2[i-1]) % ((int)1e9+7);
        }
        return dp1[n];
    }
};