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
    TreeNode *prev=nullptr, *first=nullptr, *second=nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int t=first->val;
        first->val=second->val, second->val=t;
    }
    
    void inorder(TreeNode* curr) {
        if (!curr) return;
        inorder(curr->left);
        if (prev && curr->val < prev->val) {
            if (!first) first=prev;
            second=curr;
        }
        prev=curr;
        inorder(curr->right);
    }
};