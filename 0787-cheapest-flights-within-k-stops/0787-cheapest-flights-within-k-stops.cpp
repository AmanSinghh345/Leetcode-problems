class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
          for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int cost = f[2];
            adj[u].push_back({v,cost});
        }

        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        queue<vector<int>> q;
        q.push({0,src,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            int stops=curr[0];
            int node=curr[1];
            int cost=curr[2];

            if(stops>k) continue;

            for(auto& it  : adj[node]){
                int neigh=it.first;
                int wt=it.second;
                if(cost+wt<dist[neigh]){
                    dist[neigh]=cost+wt;
                    q.push({stops+1,neigh,dist[neigh]});
                }
            }

        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};