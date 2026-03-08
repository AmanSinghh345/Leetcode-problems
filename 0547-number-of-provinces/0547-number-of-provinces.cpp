class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {   
            if(vis[adj[node][j]]==0)
            dfs(adj[node][j],vis,adj);
        }   
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(i!=j and isConnected[i][j]==1){
                    int u=i+1;
                    int v=j+1;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};