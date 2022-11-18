class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        vector<int> p(a.size(), 0), b(a.size(), 0);
        p[0]=a[0];
        int s=a[0], k=a[0], dp=a[0];
        for (int i=1; i<a.size(); i++) {
            s+=a[i];
            p[i]=max(s, p[i-1]);
            dp=max(dp, 0)+a[i];
            k=max(k, dp);
        }
        b[a.size()-1]=a[a.size()-1];
        s=a[a.size()-1];
        for (int i=a.size()-2; i>=0; i--) {
            s+=a[i];
            b[i]=max(s, b[i+1]);
        }
        int c=p[0];
        for (int i=0; i<a.size()-1; i++) {
            cout << p[i] << " " << b[i] << endl;
            c=max(c, p[i]+b[i+1]);
        }
        return max(k, c);
    }
};