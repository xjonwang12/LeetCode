class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pair<int, int>> q;
        unordered_set<int> vis;
        q.push({0, k});
        int m=0;
        while (vis.size() < n && !q.empty()) {
            int w=q.top().first, u=q.top().second;
            cout << u << " " << w << endl;
            q.pop();
            vis.insert(u);
            m=-1*w;
            for (auto v : adj[u]) {
                if (vis.find(v.first) == vis.end()) q.push({w-v.second, v.first});
            }
        }
        return (vis.size() == n) ? m : -1;
    }
};