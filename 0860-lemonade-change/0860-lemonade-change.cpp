class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0, t=0;
        for(auto b:bills) {
            if (b==5) f++;
            else if (b==10) t++, f--;
            else if (t>0) t--, f--;
            else f-=3;
            if (f<0) return false;
        }
        return true;
    }
};