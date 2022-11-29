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
    int a=0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return a;
    }
    
    int dfs(TreeNode* curr) {
        if (!curr) return 0;
        int l=0, r=0;
        l = dfs(curr->left);
        r = dfs(curr->right);
        l = (curr-> left && curr->left->val == curr->val) ? l : 0;
        r = (curr->right && curr->right->val == curr->val) ? r : 0;
        a=max(a, l+r);
        return 1 + max(l, r);
    }
};