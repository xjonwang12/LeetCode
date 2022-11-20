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
    int sumOfLeftLeaves(TreeNode* root) {
        int t=0;
        util(root, 0, t);
        return t;
    }
    
    void util(TreeNode* curr, bool isLeft, int& t) {
        if (curr==nullptr) return;
        if (isLeft && curr->left==nullptr && curr->right==nullptr) {
            t+=curr->val;
            return;
        }
        util(curr->left, 1, t);
        util(curr->right, 0, t);
    }
};