class Solution {
public:
    int n, m, s, c;
    void dfs(vector<vector<int>>& image, int i, int j) {
        if (i < 0 || j < 0 || i>= n || j >= m) return;
        if (image[i][j] != s) return;
        image[i][j] = c;
        dfs(image, i+1, j), dfs(image, i-1, j), dfs(image, i, j+1), dfs(image, i, j-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size(), s = image[sr][sc], c = color;
        if (s == c) return image;
        dfs(image, sr, sc);
        return image;
    }
};