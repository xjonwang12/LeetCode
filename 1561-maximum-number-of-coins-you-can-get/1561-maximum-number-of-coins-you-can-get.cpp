class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int m=piles.size(), i=m-2, ans=0;
        while (i>=m/3) ans+=piles[i], i-=2;
        return ans;
    }
};