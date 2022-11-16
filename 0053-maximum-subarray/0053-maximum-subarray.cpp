class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int b=INT_MIN, dp=a[0];
        for (int i=1; i<a.size(); i++) {
            b=max(b, dp);
            dp=max(dp, 0)+a[i];
        }
        return max(b, dp);
    }
};