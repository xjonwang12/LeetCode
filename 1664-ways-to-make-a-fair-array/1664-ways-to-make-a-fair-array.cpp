class Solution {
public:
    int waysToMakeFair(vector<int>& a) {
        int n=a.size(), c=0;
        vector<int> q(n, 0); q[0]=a[0];
        for (int i=1; i<n; i++) {
            q[i]=q[i-1] + ((i%2) ? -1*a[i] : a[i]);
        }
        //for (auto x:q) cout << x << " ";
        if (q[n-1]-q[0]==0) c++;
        for (int i=1; i<n; i++) {
            if (q[i-1]-(q[n-1]-q[i])==0) c++;
        }
        return c;
    }
};