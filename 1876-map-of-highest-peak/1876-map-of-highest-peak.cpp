class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Initialize the queue with all water cells and set their heights to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    matrix[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for the 4 neighbors (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // If the neighboring cell is within bounds and not yet visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] == -1) {
                    matrix[nx][ny] = matrix[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return matrix;
    }
};
