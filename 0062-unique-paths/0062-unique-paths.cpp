class Solution {
public:
    long long c(int n, int m, int r) {
        if(m==0 || r==0) return 1;
        int a=(m>r)?m:r;
        long long ans=a+1;
        for (int i=1; i<n-a; i++) {
            ans*=(i+a+1);
            ans/=i+1;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return c(m+n-2, m-1, n-1);
    }
};