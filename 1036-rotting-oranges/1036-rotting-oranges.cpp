class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q; // {{i, j}, time}
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int time = 0;

        // Step 1: Push all rotten oranges into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // Step 2: Direction vectors for 4 directions
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Step 3: BFS traversal
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int t = curr.second;
            time = max(time, t);

            for(int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                   grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2; // mark as rotten
                }
            }
        }

        // Step 4: Check for any fresh oranges left
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) return -1; // some fresh orange couldn't rot
            }
        }

        return time;
    }
};
