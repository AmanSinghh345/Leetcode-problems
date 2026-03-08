class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto& it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto& it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        if(topo.size()==n) return true;
        return false;

    }
};