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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans=INT_MIN;
        queue<pair<TreeNode*,long long >> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            long long  minInd=q.front().second;
            int first=0,last=0;
            for(int i=0;i<sz;i++){
                auto it =q.front();
                q.pop();
                if(i==0) first=it.second;
                if(i==sz-1) last=it.second;
                TreeNode* node=it.first;
                long long ind=it.second-minInd;
                if(node->left) q.push({node->left,2*ind+1});
                if(node->right) q.push({node->right,2*ind+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};