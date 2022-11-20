class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> ans;
        dfs(g, 0, g.size()-1, ans, {0});
        return ans;
    }
    
    void dfs(vector<vector<int>>& g, int s, int d, vector<vector<int>>& ans, vector<int> prev) {
        if (s==d) ans.push_back(prev);
        for (auto v : g[s]) {
            prev.push_back(v);
            dfs(g, v, d, ans, prev);
            prev.pop_back();
        }
    }
};