class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int c=0;
        while(c<costs.size() && coins>=costs[c]) {
            coins-=costs[c++];
        }
        return c;
    }
};