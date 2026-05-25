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
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            int minIndex=q.front().second;
            int first,last;
            for(int i=0;i<sz;i++){
                auto [curr,ind]=q.front();
                q.pop();
                ind-=minIndex;
                if(i==0) first=ind;
                if(i==sz-1) last=ind;
                if(curr->left)  q.push({curr->left,2*ind+1});
                if(curr->right) q.push({curr->right,2*ind+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};