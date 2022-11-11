class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0, c=0;
        for (auto k:g) {
            while (l<s.size() && s[l]<k) l++;
            if (l<s.size()) c++, l++;
        }
        return c;
    }
};