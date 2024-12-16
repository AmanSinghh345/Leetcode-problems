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
 bool isSymmetric(TreeNode* root) {
        return func(root->left,root->right)||root==nullptr;
    }
    bool func(TreeNode* root0,TreeNode* root1){
        if(root0==nullptr || root1==nullptr) return root1==root0;
        if(root0->val!=root1->val) return false;
        return func(root0->left,root1->right)&&func(root0->right,root1->left);
    }
   
};