class Solution {
public:
    vector<long long > dijkstra(int n,int i,vector<vector<pair<int,long long> >>& graph){
        const long long  INF=1e18;
        vector<long long> dist(n,INF);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        pq.push({0,i});
        dist[i]=0;
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            if(wt>dist[node]) continue;
            for(auto it: graph[node]){
                int neigh=it.first;
                long long  neighWt=it.second;
                if(dist[node]+neighWt<dist[neigh]){
                    dist[neigh]=dist[node]+neighWt;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        return dist;
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> graph_empty(n),graph_loaded(n);

        int m=roads.size();
        for(int i=0;i<m;i++){
            
                int u=roads[i][0];
                int v=roads[i][1];
                long long  cost=roads[i][2];
                long long tax=roads[i][3];
                graph_empty[u].push_back({v,cost});
                graph_empty[v].push_back({u,cost});
                graph_loaded[u].push_back({v,cost*tax});
                graph_loaded[v].push_back({u,cost*tax});
            
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){

            vector<long long> go=dijkstra(n,i,graph_empty);
            vector<long long > come=dijkstra(n,i,graph_loaded);

            long long best=LLONG_MAX;
            for(int j=0;j<n;j++){
                long long total= go[j]+prices[j]+come[j];
                best=min(best,total);
            }
            ans[i]=best;
        }
        return ans;
    }
};