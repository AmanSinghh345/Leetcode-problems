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
int minH=0;
    int dfs(TreeNode* root,int& minH)
    {
        if(root==NULL) return 0;
        int l=dfs(root->left,minH);
        int r=dfs(root->right,minH);
        minH=min(l,r);
        return 1+min(l,r);

    }
    int minDepth(TreeNode* root) {
       if(root==nullptr) return 0;
       if(root->left==nullptr) return 1+minDepth(root->right);
       if(!root->right) return 1+minDepth(root->left);
       return 1+min(minDepth(root->left),minDepth(root->right));
    }
};