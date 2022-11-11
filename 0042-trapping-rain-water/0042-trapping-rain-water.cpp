class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=1, a=0;
        while (r<height.size()) {
            int h=height[l], c=0;
            while (r<height.size() && height[r]<h) r++;
            if (r!=height.size()) {
                while(l<r) {
                    cout << h-height[l] << endl;
                    c+=h-height[l++];
                }
                l=r, r++, a+=c;
            } else {
                vector<int> t={height.rbegin(), height.rend()-l};
                a+=trap(t);
            }
        }
        
        return a;
    }
};