class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int freq[100001] = {0};
        for (auto x : nums) {
            freq[x] += 1;
        }
        int i=0,j=100000,best=0;
        while(i<=j) {
            if(freq[i] == 0){
                i++;
                continue;
            } else if(freq[j]==0) {
                j--;
                continue;
            } else {
                best = (best < i+j)?i+j:best;
                freq[i]--;
                freq[j]--;
            }
        }
        return best;
    }
};