class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c==0) return true;
        long long l=0, r=(long long) sqrt(c);
        while (l<r) {
            while (r*r+l*l>c) {
                r--;
            }
            while (r*r+l*l<c) {
                l++;
            }
            if (r*r+l*l==c) {
                return true;
            }
        }
        return false;
    }
};