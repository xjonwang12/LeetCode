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
    bool hasPathSum(TreeNode* r, int t) {
        int s=0;
        return dfs(r, t, s);
    }
    
    bool dfs(TreeNode* curr, int t, int& s) {
        if (curr==nullptr) return false;
        s+=curr->val;
        if (s==t && curr->left==nullptr && curr->right==nullptr) return true;
        if (dfs(curr->left, t, s)) return true;
        if (dfs(curr->right, t, s)) return true;
        s-=curr->val;
        return false;
    }
};