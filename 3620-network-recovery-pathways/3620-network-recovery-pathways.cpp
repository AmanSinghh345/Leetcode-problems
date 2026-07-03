class Solution {
public:
    bool find(int val, int n, vector<vector<pair<int,int>>>& adj, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;
            if (d > k)
                continue;

            for (auto &[neigh,nwt] : adj[u]) {
                if(nwt<val) continue;
                if (neigh == n - 1 && d+nwt<=k)
                    return true;
                else {
                    if (d + nwt < dist[neigh] && d+nwt<=k) {
                        dist[neigh] = d + nwt;
                        pq.push({dist[neigh], neigh});
                    }
                }
            }
        }
        if (dist[n-1] > k)
            return false;
        return true;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int high = -1;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (online[u] == false || online[v] == false)
                continue;
            high = max(high, wt);
            adj[u].push_back({v, wt});
        }

        int low = 0 ;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (find(mid, n, adj, k)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};