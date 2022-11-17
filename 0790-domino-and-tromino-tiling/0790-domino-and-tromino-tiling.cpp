class Solution {
public:
    int numTilings(int n) {
        long long dp1=1, dp2=1, dp3=0;
        for (int i=2; i<=n; i++) {
            long long t1=(dp2+dp1+dp3) % ((int)1e9+7);
            dp3=(2*dp1+dp3) % ((int)1e9+7);
            dp1=dp2, dp2=t1;
        }
        return dp2;
    }
};