class Solution {
public:
    int maxProfit(vector<int>& p) {
        int l=p[0], m=0;
        for(int i=1; i<p.size(); i++) {
            m=max(m, p[i]-l);
            l=(p[i]<l) ? p[i] : l;
        }
        return m;
    }
};