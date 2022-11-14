class Solution {
public:
    int climbStairs(int n) {
        int w1=1, w2=1;
        for (int stairs = 2; stairs <= n; stairs++) {
            w2=w1+w2;
            w1=w2-w1;
        }
        return w2;
    }
};