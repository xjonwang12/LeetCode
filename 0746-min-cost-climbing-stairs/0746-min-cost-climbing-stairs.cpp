class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        int c1=0, c2=0, n=c.size();
        for (int i=2; i<=n; i++) {
            int t=min(c1+c[i-2], c2+c[i-1]);
            c1=c2;
            c2=t;
        }
        return c2;
    }
};