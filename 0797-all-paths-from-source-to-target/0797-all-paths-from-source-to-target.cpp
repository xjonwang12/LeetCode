class Solution {
public:
    int d;
    vector<vector<int>> ans;
    vector<int> prev;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        d=g.size()-1;
        dfs(g, 0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& g, int s) {
        prev.push_back(s);
        if (s==d) ans.push_back(prev);
        for (auto v : g[s]) {
            dfs(g, v);
        }
        prev.pop_back();
    }
};