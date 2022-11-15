class Solution {
public:
    int combinationSum4(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        vector<int> dp(t+1, 0);
        dp[0]=1;
        for (int i=1; i<=t; i++) {
            for (auto c:a) {
                if (c>i) break;
                if (INT_MAX-dp[i]<dp[i-c]) break;
                dp[i]+=dp[i-c];
            }
        }
        return dp[t];
    }
};