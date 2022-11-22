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
    int c, d;
    int countPairs(TreeNode* root, int distance) {
        c=0, d=distance;
        dfs(root);
        return c;
    }
    
    vector<int> dfs(TreeNode* curr) {
        vector<int> v(d+1, 0);
        if (!curr) return v;
        if (!curr->left && !curr->right) {
            v[1]=1;
            return v;
        }
        auto l=dfs(curr->left), r=dfs(curr->right);
        for (int i=1; i<r.size(); i++) v[i]=v[i-1]+r[i];
        for (int i=1; i<l.size(); i++) c+=l[i]*v[d-i];
        v[1]=0;
        for (int i=2; i<l.size(); i++) v[i]=l[i-1]+r[i-1];
        return v;
    }
};