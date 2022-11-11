class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& numss, int target) {
        vector<vector<int>> s;
        vector<long long> nums(begin(numss), end(numss));
        sort(nums.begin(), nums.end());
        int i,j,k,l;
        for (i=0; i<(int)nums.size()-3;i++) {
            cout << i;
            if (4*nums[i]>target) break;
            if (i>0 && nums[i]==nums[i-1]) continue;
            int t=target-nums[i];
            for (j=i+1;j<(int)nums.size()-2;j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                if (2*(nums[i]+nums[j])>target) break;
                k=j+1; l=(int)nums.size()-1;
                while (k<l) {
                    if ((nums[i]+nums[j]+nums[k]+nums[l])<target) k++;
                    else if (nums[i]+nums[j]+nums[k]+nums[l]>target) l--;
                    else {
                        s.push_back({(int) nums[i], (int) nums[j], (int) nums[k], (int) nums[l]});
                        int ll=nums[k], lh=nums[l];
                        while (k<l && nums[k]==ll) k++;
                        while (k<l && nums[l]==lh) l--;
                    }
                }
            }
        }
        return s;
    }
};