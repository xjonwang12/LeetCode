class Solution {
public:
    vector<int> link, size;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        size=vector<int>(n, 1);
        for (int i=0; i<n; i++) link.push_back(i);
        for (auto e : edges) {
            if (same_unite(e[0]-1, e[1]-1)) return {e[0], e[1]};
        }
        return {0, 0};
    }
    
    int find(int x) {
        while (link[x]!=x) x=link[x];
        return x;
    }
    
    bool same_unite(int a, int b) {
        a=find(a);
        b=find(b);
        if (a==b) return true;
        if(size[a]<size[b]) {
            int t=a;
            a=b, b=t;
        }
        size[a]+=size[b];
        link[b]=a;
        return false;
    }
};