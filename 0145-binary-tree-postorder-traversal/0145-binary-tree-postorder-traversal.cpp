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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
    
        TreeNode* lastVisited=NULL;
        TreeNode* curr=root;
        while(curr!=NULL || !st.empty()){

            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }

            TreeNode* node=st.top();
            if(node->right!=NULL && node->right!=lastVisited){
                curr=node->right;
            }
            else {
                ans.push_back(node->val);
                lastVisited=node;
                st.pop();
            }
        }
        return ans;
    }
};