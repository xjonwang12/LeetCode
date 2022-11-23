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
    int t;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        t=targetSum;
        int sum=0;
        vector<int> v;
        dfs(root, sum, v);
        return ans;
    }
    
    void dfs(TreeNode* curr, int& sum, vector<int>& v) {
        if (!curr) return;
        sum+=curr->val;
        v.push_back(curr->val);
        if (!curr->left && !curr->right && sum==t) ans.push_back(v);
        else dfs(curr->left, sum, v), dfs(curr->right, sum, v);
        sum-=curr->val;
        v.pop_back();
    }
};