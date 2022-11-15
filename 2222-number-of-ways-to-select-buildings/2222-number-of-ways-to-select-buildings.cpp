class Solution {
public:
    long long numberOfWays(string s) {
        int z=s[0]-'0'==0, o=s[0]-'0';
        long long a1=0, a2=0, dp=0;
        int n=s.size();
        for (int i=1; i<n; i++) {
            if (s[i]=='0') {
                dp+=a2;
                a1+=o;
                z++;
            } else {
                dp+=a1;
                a2+=z;
                o++;
            }
        }
        return dp;
    }
};