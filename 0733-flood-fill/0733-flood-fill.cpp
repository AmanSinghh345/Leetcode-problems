class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        // queue stores row and col and original color
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        q.push({{sr, sc}, image[sr][sc]});
        int originalcolor = image[sr][sc];
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first.first;
            int col = node.first.second;
            // int originalcolor=node.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and
                     vis[nrow][ncol] == 0) {
                    int ncolor = image[nrow][ncol];
                    if (ncolor == originalcolor) {
                        q.push({{nrow, ncol}, ncolor});
                        vis[nrow][ncol] = 1;
                        image[nrow][ncol] = color;
                    }
                }
            }
        }
        return image;
    }
};