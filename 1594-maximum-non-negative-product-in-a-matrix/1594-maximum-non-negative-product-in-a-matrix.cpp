class Solution {
public:
    int mod = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            m, vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MAX})
        );

        dp[0][0] = {grid[0][0], grid[0][0]};

    
        for(int i = 1; i < m; i++) {
            long long val = dp[i-1][0].first * grid[i][0];
            dp[i][0] = {val, val};
        }


        for(int j = 1; j < n; j++) {
            long long val = dp[0][j-1].first * grid[0][j];
            dp[0][j] = {val, val};
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long val = grid[i][j];

                if(val == 0) {
                    dp[i][j] = {0, 0};
                    continue;
                }

                long long maxPos = LLONG_MIN;
                long long maxNeg = LLONG_MAX;

                // from top
                if(dp[i-1][j].first != LLONG_MIN) {
                    long long x = val * dp[i-1][j].first;
                    maxPos = max(maxPos, x);
                    maxNeg = min(maxNeg, x);
                }
                if(dp[i-1][j].second != LLONG_MAX) {
                    long long x = val * dp[i-1][j].second;
                    maxPos = max(maxPos, x);
                    maxNeg = min(maxNeg, x);
                }

                // from left
                if(dp[i][j-1].first != LLONG_MIN) {
                    long long x = val * dp[i][j-1].first;
                    maxPos = max(maxPos, x);
                    maxNeg = min(maxNeg, x);
                }
                if(dp[i][j-1].second != LLONG_MAX) {
                    long long x = val * dp[i][j-1].second;
                    maxPos = max(maxPos, x);
                    maxNeg = min(maxNeg, x);
                }

                dp[i][j] = {maxPos, maxNeg};
            }
        }

        long long res = dp[m-1][n-1].first;

        if(res < 0) return -1;
        return res % mod;
    }
};