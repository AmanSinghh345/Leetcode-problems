class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> post;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                it.second = 2;
                st.push(it);   

                if (it.first->left)
                    st.push({it.first->left, 1});
            }
            else if (it.second == 2) {
                it.second = 3;
                st.push(it);

                if (it.first->right)
                    st.push({it.first->right, 1});
            }
            else {
                post.push_back(it.first->val);
            }
        }
        return post;
    }
};
