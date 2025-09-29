class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto & it : roads)
        {
            int u=it[0],v=it[1],time=it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<long long > ways(n,0);

        dist[0]=0;
        ways[0]=1;

        priority_queue<pair<long long ,int> , vector< pair <long long , int >> , greater<>> pq;
        pq.emplace(0,0);

        const int mod=1e9 + 7 ;
        while(!pq.empty())
        {
            auto [d,node] = pq.top();
            pq.pop();

            if(d>dist[node]) continue;
            for(const auto & [neigh,time] : adj[node])
            {
                if(dist[node]+time < dist[neigh])
                {
                    dist[neigh]=dist[node] + time ;
                    ways[neigh] = ways[node];
                    pq.emplace(dist[neigh],neigh);
                }
                else if( dist[node] + time == dist[neigh])
                {
                    ways[neigh]= (ways[node] + ways[neigh])%mod;
                }
            }
        }
        return ways[n-1];
    }
};