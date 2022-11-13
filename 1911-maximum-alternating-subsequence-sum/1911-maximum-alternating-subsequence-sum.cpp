class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n=a.size();
        long long dp0=a[0], dp1=0, t0;
        for (int i=1; i<n; i++) {
            t0=max(dp1+a[i], dp0);
            dp1=max(dp0-a[i], dp1);
            dp0=t0;
        }
        return max(dp0, dp1);
    }
};