class Solution {
public:
    void dfs(int i,vector<int>& vis,vector<vector<int>>& adj){
        int n=vis.size();
        vis[i]=1;
        for(int neigh:adj[i]){
            if(vis[neigh]==0) dfs(neigh,vis,adj);
        }
         
        
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto it : invocations){
            int u=it[0];
            int v=it[1];
           adj[u].push_back(v);
        }
       
        vector<int> vis(n,0);
        dfs(k,vis,adj);
      
        for(auto it  : invocations){
            int u=it[0],v=it[1];
            if(vis[u]==0 && vis[v]==1){
                vector<int> ans;
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0) ans.push_back(i);
        }
        return ans;
    }
};