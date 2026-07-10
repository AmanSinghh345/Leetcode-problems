class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> vals(n);
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            vals[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i)
                r = i;
            while (r + 1 < n && vals[r + 1] - vals[i] <= maxDiff)
                r++;
            nxt[i] = r;
        }

        vector<vector<int>> up(n, vector<int>(LOG));
        for (int i = 0; i < n; i++) {
            up[i][0] = nxt[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int steps = 0;
            if (u > v)
                swap(u, v);
            int curr = u;

            for (int j = LOG - 1; j >= 0; j--) {

                if (up[curr][j] <v) {
                    curr = up[curr][j];
                    steps += (1 << j);
                }
            }

            if (up[curr][0] >= v) {
                steps++;
                ans.push_back(steps);
            } else
                ans.push_back(-1);
        }
        return ans;
    }
};