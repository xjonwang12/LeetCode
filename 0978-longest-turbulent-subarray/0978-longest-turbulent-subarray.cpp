class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        vector<int> dp={2, 1};
        int best=1;
        for (int i=1; i<a.size()-best+dp[1]; i++) {
            if (!dp[0]) dp={(a[i]<a[i-1]) ? 1 : (a[i]==a[i-1])?2:0, (a[i]<a[i-1])?dp[1]+1:(a[i]!=a[i-1])+1};
            else if (dp[0]==1) dp={(a[i]>a[i-1]) ? 0 : (a[i]==a[i-1])+1, (a[i]>a[i-1])?dp[1]+1:(a[i]!=a[i-1])+1};
            else {
                if (a[i]!=a[i-1]) dp={a[i]<a[i-1], 2};
            } 
            best=max(best, dp[1]);
        }
        return best;
    }
};