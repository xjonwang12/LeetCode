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
    int c=0, h=0;
    int countNodes(TreeNode* root) {
        TreeNode* curr=root;
        while (curr) {
            curr=curr->left;
            h++;
        }
        if (h==0) return 0;
        c=pow(2, --h);
        bs(root, max(1, c/2));
        return c-1;
    }
    void bs(TreeNode* curr, int l) {
        if (!curr) return;
        TreeNode* copy=curr->left;
        int d=0;
        while (copy) {
            copy=copy->right;
            d++;
        }
        cout << d << " " << h << endl;
        if (d==h--) c+=l, bs(curr->right, max(1, l/2));
        else bs(curr->left, max(1, l/2));
    }
};