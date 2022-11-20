class Solution {
public:
    int maxProfit(vector<int>& p) {
        int m=0;
        for (int i=1; i<p.size(); i++) {
            m+=(p[i]-p[i-1]>0)?p[i]-p[i-1]:0;
        }
        return m;
    }
};