class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        int dp1=0, dp2=1;
        for (int i=2; i<=n; i++) {
            dp2 = dp1+dp2;
            dp1=dp2-dp1;
        }
        return dp2;
    }
};