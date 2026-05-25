/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            if(node==NULL){
                ans+="#,";
                continue;
            }
            ans+=to_string(node->val)+",";

            q.push(node->left);
            q.push(node->right);

        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        string str;
        getline(ss,str,',');

        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            getline(ss,str,',');

            if(str!="#"){
                TreeNode* l=new TreeNode(stoi(str));
                q.push(l);
                node->left=l;
            }
            getline(ss,str,',');
            if(str!="#"){
                TreeNode* r=new TreeNode(stoi(str));
                q.push(r);
                node->right=r;
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));