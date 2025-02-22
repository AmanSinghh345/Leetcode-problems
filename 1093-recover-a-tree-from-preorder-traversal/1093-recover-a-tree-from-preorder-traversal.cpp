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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> arr;  // Stores (level, value) pairs
        int level = 0, index = 0, num = 0;
        
        while (index < traversal.size()) {
            if (traversal[index] != '-') {
                num = num * 10 + (traversal[index] - '0');
            } else {
                if (num) {  
                    arr.push_back({level, num});
                    num = 0;
                    level = 1;
                } else {
                    level++;
                }
            }
            index++;
        }
        arr.push_back({level, num}); // Add last node

        TreeNode* root = new TreeNode(arr[0].second);
        map<int, TreeNode*> mp;
        mp[0] = root;

        for (int i = 1; i < arr.size(); i++) {
            int parentLevel = arr[i].first - 1;
            TreeNode* node = new TreeNode(arr[i].second);
            mp[arr[i].first] = node;

            if (!mp[parentLevel]->left) {
                mp[parentLevel]->left = node;
            } else {
                mp[parentLevel]->right = node;
            }
        }
        
        return root;
    }
};