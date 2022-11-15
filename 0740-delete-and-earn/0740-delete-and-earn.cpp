class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int s[(int)1e4+1]={0};
        for (auto n:nums) s[n]+=n;
        int dp1=0, dp2=s[1];
        for (int i=2; i<=1e4; i++) {
            int t=max(s[i]+dp1, dp2);
            dp1=dp2, dp2=t;
        }
        return dp2;
    }
};