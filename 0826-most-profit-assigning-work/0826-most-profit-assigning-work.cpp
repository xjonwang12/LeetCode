class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int p=0;
        vector<pair<int,int>> t;
        for (int i=0; i<difficulty.size(); i++) {
            t.push_back({profit[i], difficulty[i]});
        }
        sort(t.rbegin(), t.rend());
        sort(worker.rbegin(), worker.rend());
        int l=0;
        for (auto w:worker) {
            cout<<w<<endl;
            while (l<t.size() && t[l].second>w) {
                l++;
            }
            if (l>=t.size()) break;
            p+=t[l].first;
        }
        return p;
    }
};