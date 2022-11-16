class Solution {
public:
    bool canJump(vector<int>& j) {
        int r=0, i=0;
        while (r<j.size()-1) {
            if (i>r) return false;
            r=max(r, j[i]+i++);
        }
        return true;
    }
};