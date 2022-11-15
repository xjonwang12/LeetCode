class Solution {
public:
    int dp(int i, const int* freq, vector<int>&d) {
        while (i>=0 && !freq[i]) i--;
        if (i<0) return 0;
        if (d[i]!=-1) return d[i];
        d[i]=max(i*freq[i]+dp(i-2, freq, d), dp(i-1, freq, d));
        return d[i];
    }
    int deleteAndEarn(vector<int>& nums) {
        int freq[(int)1e4+1]={0};
        for (auto n:nums) freq[n]++;
        vector<int> d(1e4+1, -1);
        return dp(1e4, freq, d);
    }
};