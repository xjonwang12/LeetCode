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
    bool findTarget(TreeNode* root, int k) {
        vector<int> list;
        inorder(root, list);
        int l=0, r=list.size()-1;
        for (auto x : list) cout << x << " ";
        while (l<r) {
            while (l<r && list[l]+list[r]<k) l++;
            while (l<r && list[l]+list[r]>k) r--;
            if (l!=r && list[l]+list[r]==k) return true;
        }
        return false;
    }
    void inorder(TreeNode* curr, vector<int>& l) {
        if (curr!=nullptr) {
            inorder(curr->left, l);
            l.push_back(curr->val);
            inorder(curr->right, l);
        }
    }
};