class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size(), a=0;
        for (int i=0; i<n; i++) {
            int m=r[i];
            vector<int> s(2, 0), l(2, 0);
            for (int j=0; j<n; j++) {
                if (r[j]>m) l[j>i]++;
                else if (r[j]<m) s[j>i]++;
            }
            a+=l[0]*s[1] + l[1]*s[0];
        }
        return a;
    }
};