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
    TreeNode* build(vector<int>& preorder,int& preIndex,int inStart,int inEnd,unordered_map<int,int>& umap){
        if(inStart>inEnd) return NULL;

        int rootVal=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootVal);

        int inRoot=umap[rootVal];

        root->left=build(preorder,preIndex,inStart,inRoot-1,umap);
        root->right=build(preorder,preIndex,inRoot+1,inEnd,umap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> umap;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        int preIndex=0;

        return build(preorder,preIndex,0,inorder.size()-1,umap);
    }
};