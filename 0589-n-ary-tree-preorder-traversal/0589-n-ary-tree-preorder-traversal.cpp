/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> l;
        preorderHelper(root, l);
        return l;
    }
    void preorderHelper(Node* curr, vector<int>& list) {
        if (curr!=nullptr) {
            list.push_back(curr->val);
            for (auto child : curr->children) {
                preorderHelper(child, list);
            }
        }
    }
};