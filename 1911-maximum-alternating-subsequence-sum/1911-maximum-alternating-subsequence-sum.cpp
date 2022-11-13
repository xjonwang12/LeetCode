class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n=a.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0]=a[0];
        for (int i=1; i<n; i++) {
            dp[i][0]=max(dp[i-1][1]+a[i], dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-a[i], dp[i-1][1]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};