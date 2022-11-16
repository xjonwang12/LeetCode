class Solution {
public:
    int jump(vector<int>& a) {
        vector<long long> dp(a.size(), INT_MAX);
        dp[a.size()-1]=0;
        for (int i=a.size()-2; i>=0; i--) {
            for (int j=1; i+j<a.size() && j<=a[i]; j++) {
                dp[i]=min(dp[i], 1+dp[i+j]);
            }
        }
        return dp[0];
    }
};