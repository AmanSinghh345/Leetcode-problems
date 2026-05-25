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
    TreeNode* build(vector<int>& postorder,int& postInd,int inStart,int inEnd,unordered_map<int,int>& umap){
        if(inStart>inEnd) return NULL;

        int rootVal=postorder[postInd--];
        TreeNode* root=new TreeNode(rootVal);
        int pos=umap[rootVal];
        root->right=build(postorder,postInd,pos+1,inEnd,umap);
        root->left=build(postorder,postInd,inStart,pos-1,umap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> umap;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        int postInd=postorder.size()-1;
        return build(postorder,postInd,0,inorder.size()-1,umap);
    }
};