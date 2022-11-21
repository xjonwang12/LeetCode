/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    vector<bool> visited;
    unordered_map<int, Employee*> ids;
    int getImportance(vector<Employee*> employees, int id) {
        visited = vector<bool>(2001, 0);
        int ans=0;
        for (auto e : employees) {
            ids.insert({e->id, e});
        }
        dfs(employees, ids[id], ans);
        return ans;
    }
    
    void dfs(vector<Employee*> employees, Employee* e, int& ans) {
        ans+=e->importance;
        visited[e->id]=1;
        for (auto u : e->subordinates) {
            dfs(employees, ids[u], ans);
        }
    }
};