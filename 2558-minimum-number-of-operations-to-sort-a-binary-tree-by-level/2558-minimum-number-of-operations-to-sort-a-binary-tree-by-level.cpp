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
    int findMinimumSwaps(vector<int>& nodeValues) {
        int minimumSwaps = 0;

        // Store Key -> Value... Value -> Actual Index Ordered Map
        map<int, int> sortedIndexMap;
        int numberOfNodes = nodeValues.size();
        for (int index = 0; index < numberOfNodes; ++index)
            sortedIndexMap[nodeValues[index]] = index;

        // Sort the array to know the expected index
        sort(nodeValues.begin(), nodeValues.end());

        vector<bool> visited(numberOfNodes, false); // This marks already processed indices
        int currentIteration = 0;    // Row number of Map
        for (auto& [value, index] : sortedIndexMap) {
            if (visited[index]) { // Don't process if already done
                currentIteration++;
                continue;
            }

            visited[index] = true;
            int cycleLength = 1; // Find length of cycle
            while (index != currentIteration) {
                index = sortedIndexMap[nodeValues[index]];
                visited[index] = true;
                cycleLength++;
            }
            minimumSwaps += cycleLength - 1; // Add number of swaps for the current loop
            currentIteration++;
        }
        return minimumSwaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        int totalSwaps = 0;
        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            vector<int> currentLevelValues;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();

                currentLevelValues.push_back(currentNode->val);
                if (currentNode->left) nodesQueue.push(currentNode->left);
                if (currentNode->right) nodesQueue.push(currentNode->right);
            }
            totalSwaps += findMinimumSwaps(currentLevelValues);
        }
        return totalSwaps;
    }
};
