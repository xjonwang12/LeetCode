class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int s=0, exp=initialExperience, ans=0;
        for (auto e:energy) s+=e;
        ans+=(s-initialEnergy+1>0)?s-initialEnergy+1:0;
        for (auto f:experience) ans += (f>=exp) ? f-exp+1 : 0, exp += (f>=exp) ? f-exp+1 : 0, exp+=f;
        return ans;
    }
};