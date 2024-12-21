class Solution {
    int dfs(vector<vector<int>>& adjacencyList, vector<int>& nodeValues, int k, int& divisibleComponents, int currentNode, int parentNode = -1) {
        long long currentSum = nodeValues[currentNode];

        for (int neighbor : adjacencyList[currentNode]) {
            if (neighbor != parentNode) {
                currentSum += dfs(adjacencyList, nodeValues, k, divisibleComponents, neighbor, currentNode);
            }
        }

        currentSum %= k;
        if (currentSum == 0) {
            divisibleComponents++;
        }

        return currentSum;
    }

public:
    int maxKDivisibleComponents(int numNodes, vector<vector<int>>& edges, vector<int>& nodeValues, int k) {
        vector<vector<int>> adjacencyList(numNodes);
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        int divisibleComponents = 0;
        dfs(adjacencyList, nodeValues, k, divisibleComponents, 0, -1);
        return divisibleComponents;
    }
};
