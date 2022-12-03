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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<pair<int, TreeNode*>> q;
        q.push({1, root});
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (u.first == depth-1) {
                auto left = u.second->left;
                u.second->left = new TreeNode(val, left, nullptr);
                auto right = u.second->right;
                u.second->right = new TreeNode(val, nullptr, right);
            }
            else if (u.first < depth-1) {
                if (u.second->left) q.push({u.first+1, u.second->left});
                if (u.second->right) q.push({u.first+1, u.second->right});
            }
        }
        return root;
    }
};