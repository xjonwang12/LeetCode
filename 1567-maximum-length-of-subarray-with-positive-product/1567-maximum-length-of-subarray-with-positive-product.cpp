class Solution {
public:
    int getMaxLen(vector<int>& a) {
        int m=(a[0]>0), dp1=a[0]>0, dp2=a[0]<0;
        for (int i=1; i<a.size(); i++) {
            if (a[i] > 0) dp1=dp1+1, dp2=dp2?dp2+1:0;
            else if (a[i] < 0) {
                int t=dp2?dp2+1:0;
                dp2=dp1+1, dp1=t;
            }
            else dp1=0, dp2=0;
            m=max(m, dp1);
        }
        return m;
    }
};