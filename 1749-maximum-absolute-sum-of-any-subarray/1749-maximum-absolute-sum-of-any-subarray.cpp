class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n=a.size(), c=abs(a[0]);
        vector<pair<int, int>> dp(n,{0, 0});
        dp[0]={(a[0]>0) ? a[0] : 0, (a[0]<0) ? a[0] : 0};
        for (int i=1; i<n; i++) {
            dp[i].first = (dp[i-1].first+a[i] > a[i]) ? dp[i-1].first+a[i] : a[i];
            dp[i].second = (dp[i-1].second+a[i] < a[i]) ? dp[i-1].second+a[i] : a[i];
            c=max(c, max(dp[i].first, -1*dp[i].second));
        }
        return c;
    }
};