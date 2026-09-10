class Solution {
private:
    int countMatching = 0;

    
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) return {0, 0};

        auto leftStats = postOrder(root->left);
        auto rightStats = postOrder(root->right);

        int currentSum = root->val + leftStats.first + rightStats.first;
        int currentCount = 1 + leftStats.second + rightStats.second;

        if (currentSum / currentCount == root->val) {
            countMatching++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return countMatching;
    }
};