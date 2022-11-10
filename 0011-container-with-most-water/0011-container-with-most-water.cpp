class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, best=0;
        while(left<right) {
            int x = (height[left]<height[right]) ? height[left]:height[right];
            best = (best < x*(right-left))?x*(right-left):best;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return best;
    }
};