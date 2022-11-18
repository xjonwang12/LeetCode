class Solution {
public:
    int maxProduct(vector<int>& a) {
        int m=a[0], dp1=(a[0]>0)?a[0]:0, dp2=(a[0]<0)?a[0]:0;
        for (int i=1; i<a.size(); i++) {
            // cout << dp1 << " " << dp2 << endl;
            int t=max(a[i], max(dp1*a[i], dp2*a[i]));
            dp2=min(a[i], min(dp1*a[i], dp2*a[i]));
            dp1=t;
            m=max(m, dp1);
        }
        return m;
    }
};