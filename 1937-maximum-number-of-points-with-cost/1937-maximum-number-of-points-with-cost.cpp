class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        vector<long long> dp;
        for (auto x : p[0]) dp.push_back(x);
        for (int i=1; i<p.size(); i++) {
            vector<long long> temp(dp.size(), -1);
            vector<long long> l(dp.size(), -1), r(dp.size(), -1);
            l[0]=dp[0];
            for (int k=1; k<dp.size(); k++) {
                l[k]=max(l[k-1], dp[k]+k);
            }
            /*
            for (auto x:l) {
                cout << x << " ";
            }
            */
            cout << endl;
            r[dp.size()-1]=dp[dp.size()-1]-dp.size()+1;
            for (int k=dp.size()-2; k>=0; k--) {
                r[k]=max(r[k+1], dp[k]-k);
            }
            /*
            for (auto x:r) {
                cout << x << " ";
            }
            */
            cout << endl;
            for (int j=0; j<p[0].size(); j++) {
                temp[j] = max(l[j]-j, r[j]+j) + p[i][j];
            }
            /*
            for (auto x:temp) {
                cout << x << " ";
            }
            */
            cout << endl;
            dp=temp;
        }
        long long m=0;
        for (int i=0; i<p[0].size(); i++) m=(m>=dp[i])?m:dp[i];
        return m;
    }
};