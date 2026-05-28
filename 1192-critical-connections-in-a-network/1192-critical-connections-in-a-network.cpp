class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& low,vector<int>& tin,vector<int>& vis ,vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]=low[node]=timer++;

        for(auto& neigh : adj[node]){
            if(neigh==parent) continue;
            
            //back edge
            if(vis[neigh]){
                low[node]=min(low[node],tin[neigh]);
            }
            else{
                dfs(neigh,node,adj,low,tin,vis,bridges);
                low[node]=min(low[node],low[neigh]);

                if(low[neigh]>tin[node]){
                    bridges.push_back({node,neigh});
                }
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& connection : connections){
            int u=connection[0];
            int v=connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n),low(n),vis(n,0);
        vector<vector<int>> bridges;
        for (int i = 0; i < n; i++) {
    if (!vis[i]) {
        dfs(i, -1, adj,
            low, tin,
            vis, bridges);
    }
    return bridges;
}

        return bridges;
    }
};