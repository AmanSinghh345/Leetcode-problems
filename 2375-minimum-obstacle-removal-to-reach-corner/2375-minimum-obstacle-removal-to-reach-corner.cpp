#define Pair pair<int, pair<int, int>>
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> directions = {-1, 0, 1, 0, -1};
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        priority_queue<Pair, vector<Pair>, greater<Pair>> queue;
        queue.push({0, {0, 0}});
        seen[0][0] = true;
        while (!queue.empty()) {
            Pair current = queue.top();
            queue.pop();
            int x = current.second.first;
            int y = current.second.second;
            int cost = current.first;
            if (x == rows - 1 && y == cols - 1)
                return cost;
            for (int i = 0; i < 4; ++i) {
                int newX = x + directions[i];
                int newY = y + directions[i + 1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                    !seen[newX][newY]) {
                    seen[newX][newY] = true;
                    if (matrix[newX][newY] == 1) {
                        queue.push({cost + 1, {newX, newY}});
                    } else {
                        queue.push({cost, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};