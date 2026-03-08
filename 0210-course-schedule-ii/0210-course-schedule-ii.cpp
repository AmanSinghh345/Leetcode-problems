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
       int n=numCourses;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<int> indegree(n);
        for(int i=0;i<n;i++)
        {
            for(auto&it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0 ) q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto& it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()==n) return ans;
        return {};
    }
};
