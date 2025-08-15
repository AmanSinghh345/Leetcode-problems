class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
         vector<int> inDegree(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }
        vector<int> ans;
       
        for(int i=0;i<n;i++)
        {
            for(auto& it: adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto& it : adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        if(ans.size()!=n) return false;
        return true;
    }
};