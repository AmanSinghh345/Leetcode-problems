class Solution {
public:
    struct State {
    int x, y, energy, mask, steps;
         };

int minMovesToClean(vector<string>& classroom, int maxEnergy) {
   int m = classroom.size(), n = classroom[0].size();
    int totalLitter = 0;
    map<pair<int, int>, int> litterIndex;
    int startX, startY;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (classroom[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (classroom[i][j] == 'L') {
                litterIndex[{i, j}] = totalLitter++;
            }
        }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<State> q;

    unordered_map<int, unordered_map<int, unordered_map<int, int>>> visited;

    q.push({startX, startY, maxEnergy, 0, 0});
    visited[startX][startY][0] = maxEnergy;

    while (!q.empty()) {
        auto [x, y, energy, mask, steps] = q.front();
        q.pop();

        if (mask == (1 << totalLitter) - 1)
            return steps;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            int newEnergy = energy - 1;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (classroom[nx][ny] == 'X')
                continue;
            if (newEnergy < 0)
                continue;

            if (classroom[nx][ny] == 'R')
                newEnergy = maxEnergy;

            int newMask = mask;
            if (classroom[nx][ny] == 'L')
                newMask |= (1 << litterIndex[{nx, ny}]);

        
            if (visited[nx][ny].count(newMask) && visited[nx][ny][newMask] >= newEnergy)
                continue;

            visited[nx][ny][newMask] = newEnergy;
            q.push({nx, ny, newEnergy, newMask, steps + 1});
        }
    }

    return -1;
}
    int minMoves(vector<string>& classroom, int energy) {
       return  minMovesToClean(classroom,energy);
    }
};