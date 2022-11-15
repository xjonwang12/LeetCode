class Solution {
public:
    int rob(vector<int>& a) {
        int dp1=0, dp2=a[0];
        for (int i=1; i<a.size(); i++) {
            int t=max(a[i]+dp1, dp2);
            dp1=dp2, dp2=t;
        }
        return dp2;
    }
};