class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        vector<int> d(houses.size());
        for (int i=0; i<houses.size(); i++) {
            int h=houses[i];
            vector<int>::iterator u, l;
            u = lower_bound(heaters.begin(), heaters.end(), h);
            if (u == heaters.begin()) d[i] = *u-h;
            else if (u == heaters.end()) d[i] = h-*(u-1);
            else {
                l = u-1;
                d[i]=(*u-h > h-*l)?h-*l:*u-h;
            }
            cout << d[i] << endl;
        }
        int b=0;
        for (auto x:d) {
            b=(b>=x)?b:x;
        }
        return b;
    }
};