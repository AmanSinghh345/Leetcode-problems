class Solution {
public:
    vector<long long > dijkstra(int n,int i,vector<vector<pair<int,long long >>>& adj){
        const long long INF=1e18;
        vector<long long> dist(n,INF);

        priority_queue<pair<long long ,int >,vector<pair<long long ,int>>,greater<>> pq;
        pq.push({0,i});
        dist[i]=0;
        while(!pq.empty()){
            auto[d,u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;

            for(auto [v,wt]:adj[u]){
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }

        }
        return dist;
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj1(n),adj2(n);

        for(auto& road:roads){
            int u=road[0];
            int v=road[1];
            long long cost=road[2];
            long long tax=road[3];

            // cost graph
            adj1[u].push_back({v,cost});
            adj1[v].push_back({u,cost});

            //cost*tax graph
            adj2[u].push_back({v,cost*tax});
            adj2[v].push_back({u,cost*tax});
             
        }

        
        vector<int> ans(n);

        for(int i=0;i<n;i++){

            vector<long long> go=dijkstra(n,i,adj1);
            vector<long long> come=dijkstra(n,i,adj2);

            long long best=LLONG_MAX;
            for(int j=0;j<n;j++){
                long long total=go[j]+prices[j]+come[j];
                best=min(best,total);
            }
            ans[i]=best;
        }
        return ans;
    }
};