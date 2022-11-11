class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, k, c = 0;
        for (k = 2; k < nums.size(); k++) {
            i = 0, j = k-1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) c += j-i, j--;
                else i++;
            }
        }
        return c;
    }
};