class Solution {
public:
    vector<bool> vis;
    bool canReach(vector<int>& a, int s) {
        vis=vector<bool>(a.size(), 0);
        return dfs(a, s);
    }
    
    bool dfs(vector<int>& a, int s) {
        vis[s]=1;
        if (a[s]==0) return true;
        if (s-a[s]>=0 && !vis[s-a[s]] && dfs(a, s-a[s])) return true;
        if (s+a[s]<a.size() && !vis[s+a[s]] && dfs(a, s+a[s])) return true;
        return false;
    }
};