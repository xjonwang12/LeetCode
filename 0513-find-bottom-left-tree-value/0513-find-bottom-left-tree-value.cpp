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
    int findBottomLeftValue(TreeNode* root) {
        int ans, depth=-1;
        util(root, 0, depth, ans);
        return ans;
    }
    
    void util(TreeNode* curr, int level, int& depth, int& ans) {
        if (curr==nullptr) return;
        if (level>depth) depth=level, ans=curr->val;
        util(curr->left, level+1, depth, ans);
        util(curr->right, level+1, depth, ans);
    }
};