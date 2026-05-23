class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mat(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=grid[i][j];
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {

            if (grid[i][0] == 1)
             {   q.push({i, 0});
                mat[i][0]=0;
             }
            if (grid[i][n - 1] == 1){
                q.push({i, n - 1});
                mat[i][n-1]=0;
                }
        }
        for (int j = 1; j < n-1; j++) {
            if (grid[0][j]){
                q.push({0, j});
                mat[0][j]=0;
                }
            if (grid[m - 1][j]){
                q.push({m - 1, j});
                mat[m-1][j]=0;
                }
        }
        int ans = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    mat[nx][ny] == 1) {
                    mat[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]) ans++;
            }
        }
        return ans;
    }
};