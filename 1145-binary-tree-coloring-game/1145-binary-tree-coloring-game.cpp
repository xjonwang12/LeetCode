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
    int a;
    TreeNode* p1;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (root->val == x) {
            int c=0;
            dfs(root->left, c);
            return c!=n/2;
        }
        a=x;
        int l=0, r=0;
        find(root);
        dfs(p1->left, l), dfs(p1->right, r);
        return l+r < n/2 || l > n/2 || r > n/2;
    }
    
    void dfs(TreeNode* curr,  int& c) {
        if (!curr) return;
        c++;
        dfs(curr->left, c), dfs(curr->right, c);
    }
    
    bool find(TreeNode* curr) {
        if (!curr) return false;
        if (curr->val==a) {
            p1=curr;
            return true;
        }
        if (find(curr->left) || find(curr->right)) return true;
        return false;
    }
};