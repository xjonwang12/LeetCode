class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n=a.size(), i;
        deque<pair<int, int>> q;
        q.push_back({n-1, a[n-1]});
        for (i=n-2; i>=max(0, n-k); i--) {
            int t = q.front().second + a[i];
            while (!q.empty() && q.back().second <= t) q.pop_back();
            q.push_back({i, t});
        }
        for (;i>=0; i--) {
            int t = q.front().second + a[i];
            while (!q.empty() && q.front().first>=i+k) q.pop_front();
            while (!q.empty() && q.back().second <= t) q.pop_back();
            q.push_back({i, t});
        }
        /*
        while (!q.empty()) {
            cout << q.front().second << " ";
            q.pop_front();
        }
        cout << endl;
        */
        return q.back().second;
    }
};