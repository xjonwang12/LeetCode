class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i,j,k;
        pair<int,int> b={INT_MAX,0};
        for (i=0;i<nums.size()-2;i++) {
            if (b.first==0) break;
            j=i+1; k=nums.size()-1;
            while (j<k) {
                if (nums[i]+nums[j]+nums[k]-target<=-b.first) {
                    j++;
                } else if (nums[i]+nums[j]+nums[k]-target>=b.first) {
                    k--;
                } else {
                    b={abs(nums[i]+nums[j]+nums[k]-target), (nums[i]+nums[j]+nums[k]-target>=0)?1:-1};
                }
            }
        }
        return target+b.first*b.second;
    }
};