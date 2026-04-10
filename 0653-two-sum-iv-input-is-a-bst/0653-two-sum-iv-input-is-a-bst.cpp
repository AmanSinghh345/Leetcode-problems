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
    void inorder(TreeNode* root,vector<int>&res){
        if(root==NULL) return ;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL ) return false;
        unordered_map<int,int> umap;
        vector<int> res;
        inorder(root,res);

        int n=res.size();
        for(int i=0;i<n;i++){
            if(umap.find(k-res[i])!=umap.end()) return true;
            umap[res[i]]++;
        }
        return false;

    }
};