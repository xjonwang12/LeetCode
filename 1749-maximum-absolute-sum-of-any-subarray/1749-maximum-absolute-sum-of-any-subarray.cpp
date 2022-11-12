class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n=a.size(), c=abs(a[0]);
        pair<int, int> dp = {(a[0]>0) ? a[0] : 0, (a[0]<0) ? a[0] : 0};
        for (int i=1; i<n; i++) {
            dp.first = (dp.first+a[i] > a[i]) ? dp.first+a[i] : a[i];
            dp.second = (dp.second+a[i] < a[i]) ? dp.second+a[i] : a[i];
            c=max(c, max(dp.first, -1*dp.second));
        }
        return c;
    }
};