class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
unordered_map<int, int> degreeCount;

// Build graph and count in/out degrees
for (const auto& edge : pairs) {
    graph[edge[0]].push_back(edge[1]);
    degreeCount[edge[0]]++;  // out-degree
    degreeCount[edge[1]]--;  // in-degree
}

// Find starting node
int initialNode = pairs[0][0];
for (const auto& [node, degree] : degreeCount) {
    if (degree == 1) {
        initialNode = node;
        break;
    }
}

vector<int> traversalPath;
stack<int> traversalStack;
traversalStack.push(initialNode);

while (!traversalStack.empty()) {
    auto& adjacentNodes = graph[traversalStack.top()];
    if (adjacentNodes.empty()) {
        traversalPath.push_back(traversalStack.top());
        traversalStack.pop();
    } else {
        int nextNode = adjacentNodes.back();
        traversalStack.push(nextNode);
        adjacentNodes.pop_back();
    }
}

vector<vector<int>> result;
int pathLength = traversalPath.size();
result.reserve(pathLength - 1);

for (int i = pathLength - 1; i > 0; --i) {
    result.push_back({traversalPath[i], traversalPath[i - 1]});
}

return result;

    }
};