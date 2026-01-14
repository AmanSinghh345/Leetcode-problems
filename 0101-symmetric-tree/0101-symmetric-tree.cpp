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
    bool f(TreeNode* node0,TreeNode* node1)
    {
        if(node0==nullptr or node1==nullptr) return node0==node1;
        if(node0->val!=node1->val) return false;

        return f(node0->left,node1->right) and f(node0->right,node1->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return f(root->left,root->right);
    }
};