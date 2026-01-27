class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
       vector<vector<pair<int,int>>> adjList(n);
       for(auto &e:edges)
       {
         int u,v,d;
         u=e[0];
         v=e[1];
         d=e[2];
         adjList[u].push_back({v,d});
         adjList[v].push_back({u,2*d});
       }

        vector<int> dist(n,INT_MAX);
        dist[0]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

           for(auto &[next,w]:adjList[node])
           {
             if(dist[next]> d + w)
             {
                dist[next]=d+w;
                pq.push({dist[next],next});
             }
           }
        }
        if(dist[n-1]==INT_MAX) return -1;
        return dist[n-1];
    }
};