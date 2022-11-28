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
    vector<int> l;
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root, 1, 0);
    }
    
    int dfs(TreeNode* curr, unsigned int i, int d) {
        if (!curr) return 0;
        if (d==l.size()) l.push_back(i);
        return max((int) (i-l[d]+1), max(dfs(curr->left, 2*i, d+1), dfs(curr->right, 2*i+1, d+1)));
    }
};