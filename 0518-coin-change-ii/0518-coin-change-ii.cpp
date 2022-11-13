class Solution {
public:
    int change(int a, vector<int>& c) {
        vector<int> dp1(a+1, 0), dp2(a+1, 0);
        dp1[0]=1, dp2[0]=1;
        int n=c.size();
        for (int i=0; i<n; i++) {
            for (int j=1; j<=a; j++) {
                if (j>=c[i]) dp2[j]=dp2[j-c[i]] + dp1[j];
                else dp2[j]=dp1[j];
            }
            dp1=dp2;
            dp2=vector<int>(a+1, 0);
            dp2[0]=1;
        }
        return dp1[a];
    }
};