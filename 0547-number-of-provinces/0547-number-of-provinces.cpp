class Solution {
public:
    void dfs(vector<int>& ans,vector<int>& vis,vector<vector<int>>& adj,int node){
        vis[node]=1;
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            if(vis[adj[node][i]]==0)
            {
                dfs(ans,vis,adj,adj[node][i]);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j and isConnected[i][j]==1)
                {
                    int u=i+1;
                    int v=j+1;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vector<int> vis(n+1,0);
        vector<int> ans;
        int provinces=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {   
                provinces++;
                dfs(ans,vis,adj,i);
            }
        }
        return provinces;
    }
};