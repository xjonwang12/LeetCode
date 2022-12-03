/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int c=0;
    void dfs(TreeNode* u, int& m) {
        if (!u) return;
        if (u->val >= m) c++;
        int t=m;
        m=max(u->val, m);
        dfs(u->left, m), dfs(u->right, m);
        m=t;
    }
    int goodNodes(TreeNode* root) {
        int m=INT_MIN;
        dfs(root, m);
        return c;
    }
};