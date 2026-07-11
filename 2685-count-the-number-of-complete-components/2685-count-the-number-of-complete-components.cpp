class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& comp){
        vis[node]=1;
        comp.push_back(node);
        for(int neigh:adj[node]){
            if(!vis[neigh]) dfs(neigh,vis,adj,comp);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> comp;
                dfs(i,vis,adj,comp);
                bool ok=true;
                for(int x:comp){
                    if(adj[x].size()!=comp.size()-1) {
                        ok=false;
                        break;
                    }
                }
                if(ok) cnt++;
            }
        }
        return cnt;
    }
};