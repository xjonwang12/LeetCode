class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        vector<int> f, b;
        int n=arr.size()-1;
        int l=0, r=n;
        do {
            f.push_back(arr[l++]);
        } while (l<=n && arr[l-1]<=arr[l]);
        do {
            b.push_back(arr[r--]);
        } while (r>=0 && arr[r]<=arr[r+1]);
        if (b.size() == n+1) return 0;
        int c=0, t=0;
        for (int i=f.size()-1; i>=0; i--) {
            while(t<b.size() && b[t]>=f[i]) {
                t++;
            }
            c=(c>t+i+1) ? c : t+i+1;
        }
        c=(c>b.size()) ? c : b.size();
        return n-c+1;
    }
};