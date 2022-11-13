class Solution {
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        int dp1=0, dp2=1, dp3=1;
        for (int i=3; i<=n; i++) {
            int temp=dp1+dp2+dp3;
            dp1=dp2, dp2=dp3, dp3=temp;
        }
        return dp3;
    }
};