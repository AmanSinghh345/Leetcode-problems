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
    int find(TreeNode* root,int& maxi){
        if(root==nullptr) return 0;
        int lsum=max(0,find(root->left,maxi));
        int rsum=max(0,find(root->right,maxi));
        maxi=max(maxi,lsum+root->val+rsum);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxi=INT_MIN;
        find(root,maxi);
        return maxi;
    }
};