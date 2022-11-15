class Solution {
public:
    int rob(vector<int>& a) {
        if (a.size()==1) return a[0];
        int dp1=0, dp2=a[1];
        for (int i=2; i<a.size(); i++) {
            int t=max(dp1+a[i], dp2);
            dp1=dp2, dp2=t;
        }
        int dp3=0, dp4=a[0];
        for (int i=1; i<a.size()-1; i++) {
            int t=max(dp3+a[i], dp4);
            dp3=dp4, dp4=t;
        }
        return max(dp2, dp4);
    }
};