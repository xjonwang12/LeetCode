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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        util(root, ans);
        return ans;
    }
    
    pair<int, int> util(TreeNode* curr, int& ans) {
        if (curr==nullptr) return {0, 0};
        pair<int, int> l = util(curr->left, ans), r = util(curr->right, ans);
        int sum = l.first+r.first+curr->val, count = l.second+r.second+1;
        if (sum / count == curr->val) ans++;
        return {sum, count};
    }
};