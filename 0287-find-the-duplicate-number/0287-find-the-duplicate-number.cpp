class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool freq[100001]={0};
        for(auto x:nums){
            if (freq[x]) return x;
            freq[x]=1;
        }
        return -1;
    }
};