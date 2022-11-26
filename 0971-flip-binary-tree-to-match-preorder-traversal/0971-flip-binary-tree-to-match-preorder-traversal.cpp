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
    int i=0;
    vector<int> v, a;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        v=voyage;
        if (dfs(root)) return a;
        return vector<int>(1, -1);
    }
    
    bool dfs(TreeNode* curr) {
        if (!curr) return true;
        if (curr->val != v[i++]) return false;
        if (curr->left && curr->left->val != v[i]) {
            a.push_back(curr->val);
            if (!dfs(curr->right) || !dfs(curr->left)) return false;
        }
        else if (!dfs(curr->left) || !dfs(curr->right)) return false;
        return true;
    }
};