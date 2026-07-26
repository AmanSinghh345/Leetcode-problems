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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int> level(sz);
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();

                int ind=ltr?i:sz-i-1;
                level[ind]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            ltr=!ltr;
            ans.push_back(level);
        }
        return ans;
    }
};