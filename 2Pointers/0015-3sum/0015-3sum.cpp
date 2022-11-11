class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> c;
        int i, j, k;
        for (i=0; i<nums.size()-2; i++) {
            if (nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            j=i+1; k=nums.size()-1;
            while (j<k) {
                if (nums[i]+nums[j]+nums[k]>0) k--;
                else if (nums[i]+nums[j]+nums[k]<0) j++;
                else {
                    int ll=nums[j], lh=nums[k];
                    c.push_back({nums[i], nums[j], nums[k]});
                    while (j<k && nums[j]==ll) {
                        j++;
                    }
                    while (j<k && nums[k]==lh) {
                        k--;
                    }
                }
            }
        }
        return c;
    }
};