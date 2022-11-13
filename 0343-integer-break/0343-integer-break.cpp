class Solution {
public:
    int integerBreak(int n) {
        int m=n/3, r=n%3;
        if (n==2) return 1;
        if (n==3) return 2;
        if (r==0) return pow(3, m);
        else if (r==1) return 4*pow(3, m-1);
        else return 2*pow(3, m);
    }
};