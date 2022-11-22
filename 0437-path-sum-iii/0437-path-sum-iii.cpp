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
    unordered_map<long, int> sums;
    int c, t;
    int pathSum(TreeNode* root, int targetSum) {
        c=0, t=targetSum;
        dfs(root, 0);
        return c;
    }
    
    void dfs(TreeNode* curr, long sum) {
        if (!curr) return;
        sum+=curr->val;
        if (sum==t) c++;
        if (sums.find(sum-t) != sums.end()) c+=sums[sum-t];
        sums[sum]++;
        dfs(curr->left, sum);
        dfs(curr->right, sum);
        sums[sum]--;
    }
};