class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        vector<vector<int>> best(m, vector<int>(n, -1));
        best[0][0] = dist[0][0];
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [curr, x, y] = pq.top();
            pq.pop();
            if(x==m-1 && y==n-1) return curr;
            if (curr < best[x][y])
                continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int val = min(curr, dist[nx][ny]);
                    if (val > best[nx][ny]) {
                        best[nx][ny] = val;
                        pq.push({best[nx][ny], nx, ny});
                    }
                }
            }
        }
        return 0;
    }
};