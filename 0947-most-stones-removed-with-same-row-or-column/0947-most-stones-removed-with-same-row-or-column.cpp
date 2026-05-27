class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(int neigh : adj[node]){
            if(vis[neigh]==-1) dfs(neigh,vis,adj);
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1=stones[i][0],y1=stones[i][1];
                int x2=stones[j][0],y2=stones[j][1];

                if(x1==x2 || y1==y2){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int components=0;
        vector<int> vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                components++;
                dfs(i,vis,adj);
            }
        }
        return n-components;
    }
};