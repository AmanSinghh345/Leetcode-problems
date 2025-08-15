class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis, stack<int>& st) {
        vis[node] = 1; // visiting
        for (auto &it : adj[node]) {
            if (vis[it] == 0) {
                if (!dfs(adj, it, vis, st)) return false; // cycle detected in recursion
            } else if (vis[it] == 1) {
                return false; // back edge -> cycle
            }
        }
        vis[node] = 2; // processed
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto &p : prerequisites) {
            int u = p[1], v = p[0];
            adj[u].push_back(v);
        }

        stack<int> st;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (!dfs(adj, i, vis, st)) return {}; // cycle detected
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
