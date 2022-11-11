class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c=0, m=flowerbed.size();
        for (int i=0;i<m;i++) if (!flowerbed[i]) c+=((i-1<0 || !flowerbed[i-1])&&(i+1>=m || !flowerbed[++i]));
        return c>=n;
    }
};