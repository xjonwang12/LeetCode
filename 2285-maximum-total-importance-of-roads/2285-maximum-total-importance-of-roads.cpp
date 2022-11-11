class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long a=0;
        vector<int> imp(n, 0);
        for (auto v:roads) {
            for (auto x:v) imp[x]++;
        }
        sort(imp.begin(), imp.end());
        for (long long i=n-1; i>=0; i--) a+=(i+1)*imp[i];
        return a;
    }
};