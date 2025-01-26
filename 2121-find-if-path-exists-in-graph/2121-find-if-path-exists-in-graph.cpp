class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create adjacency list using unordered_map
        unordered_map<int, vector<int>> umap;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        
        // BFS to check if there's a path from source to destination
        vector<bool> visited(n, false);  // Use size n for visited array
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // If destination is found, return true
            if (u == destination) return true;

            for (int neighbor : umap[u]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // If we exhaust BFS and don't reach the destination, return false
        return false;
    }
};
