class Solution {
public:
    unordered_set<int> vis;
    int n;
    void dfs(vector<vector<int>>& rooms, int u) {
        if (vis.find(u) != vis.end()) return;
        vis.insert(u);
        for (auto v : rooms[u]) {
            if (vis.find(v) == vis.end()) dfs(rooms, v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        dfs(rooms, 0);
        return vis.size() == n;
    }
};