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
    void find(TreeNode* node,int level,vector<int>& ans){
        if(node==nullptr) return ;
        if(ans.size()==level) ans.push_back(node->val);
        if(node->right) find(node->right,level+1,ans);
        if(node->left) find(node->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        find(root,0,ans);
        return ans;
    }
};