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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map  vl , hl,multiset values
        // queue node, vl,hl
        if(root==nullptr) return {};
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int vl=it.second.first;
            int hl=it.second.second;

            //insert in map
            mp[vl][hl].insert(node->val);

            if(node->left) q.push({node->left,{vl-1,hl+1}});
            if(node->right) q.push({node->right,{vl+1,hl+1}});
            
        }

        for(auto it:mp){  // -2 -1 0 1 2 
            vector<int> temp;
            for(auto itt:it.second){  // down 
                temp.insert(temp.end(),itt.second.begin(),itt.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};