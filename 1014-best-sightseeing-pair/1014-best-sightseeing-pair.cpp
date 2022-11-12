class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n, 0);
        dp[1]=a[0]+a[1]-1;
        int c=dp[1];
        for (int i=2; i<n; i++) dp[i]=max(dp[i-1] - a[i-1], a[i-1]) + a[i] - 1, c=max(c, dp[i]);
        return c;
    }
};