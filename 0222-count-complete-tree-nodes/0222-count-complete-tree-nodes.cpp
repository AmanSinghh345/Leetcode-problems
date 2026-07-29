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
    int findLeftHeight(TreeNode* node){
        int cnt=0;
        while(node!=nullptr){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    int findRightHeight(TreeNode* node){
        int cnt=0;
        while(node!=nullptr){
            cnt++;
            node=node->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh) return (1<<rh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};