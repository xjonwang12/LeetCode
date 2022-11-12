class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int n=s.size();
        vector<vector<int>> dp(n, {0, 0});
        dp[0] = {1, 1};
        for (int i=1; i<n; i++) {
            dp[i][0] = (s[i]>=s[i-1]) ? dp[i-1][0]+1 : 1;
            dp[i][1] = (s[i]<=s[i-1]) ? dp[i-1][1]+1 : 1;
            /*
            for (auto x:dp[i]) {
                cout << x << " ";
            }
            cout << endl;
            */
        }
        vector<int> a;
        for (int i=t; i<n-t; i++) {
            if (dp[i][1]>t && dp[i+t][0]>t) {
                a.push_back(i);
            }
        }
        return a;
    }
};