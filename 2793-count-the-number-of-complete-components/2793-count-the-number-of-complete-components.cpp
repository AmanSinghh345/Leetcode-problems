class Solution {
public:
    void createAdj(vector<vector<int>> &adj, vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void bfs(vector<vector<int>> &adj, int s, vector<int> &visited, vector<int> &components, vector<pair<int, int>> &edgesInComponent) {
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Add the current vertex to the component
            components.push_back(u);

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }

                // Add the edge only once (u < v ensures no duplication)
                if (u < v) {
                    edgesInComponent.push_back({u, v});
                }
            }
        }
    }

    int BFSDis(vector<vector<int>> &adj, int n) {
        vector<int> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> components;
                vector<pair<int, int>> edgesInComponent;

                // Perform BFS to explore the component
                bfs(adj, i, visited, components, edgesInComponent);

                // Check if the component is complete
                int k = components.size();              // Number of vertices in the component
                int expectedEdges = (k * (k - 1)) / 2; // Edges in a complete graph with k vertices
                int actualEdges = edgesInComponent.size();

                if (actualEdges == expectedEdges) {
                    count++;
                }
            }
        }

        return count;
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n); // Adjacency list of size n
        createAdj(adj, edges);
        return BFSDis(adj, n);
    }
};
