class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& time : times){
            int u=time[0];
            int v=time[1];
            int cost=time[2];
            adj[u].push_back({v,cost});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int cost=curr.first;
            int node=curr.second;
            if(cost>dist[node]) continue;

            for(auto& [neigh,price]:adj[node]){
                if(cost+price<dist[neigh]){
                    dist[neigh]=cost+price;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};