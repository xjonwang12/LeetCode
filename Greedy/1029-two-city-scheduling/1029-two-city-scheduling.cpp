class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> v;
        for (auto c:costs) {
            v.push_back({c[0]-c[1], c[0], c[1]});
        }
        sort(v.begin(), v.end());
        int ans=0, i=0;
        for (i=0; i<costs.size()/2; i++) ans+=v[i][1];
        while (i<costs.size()) ans+=v[i++][2];
        return ans;
    }
};