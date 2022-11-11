class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> flips;
        vector<int> p = {1, 2, 3, 4};
        for (int i = arr.size(); i > 1; i--) {
            pair<int, int> best = {0, 0};
            for (int j = 0; j<i;j++) if (arr[j] > best.first) best = {arr[j], j};
            if (best.second == i - 1) continue;
            else {
                flips.push_back(best.second + 1);
                std::reverse(arr.begin(), arr.begin()+best.second+1);
                flips.push_back(i);
                reverse(arr.begin(), arr.begin()+i);
            }
        }
        return flips;
    }
};