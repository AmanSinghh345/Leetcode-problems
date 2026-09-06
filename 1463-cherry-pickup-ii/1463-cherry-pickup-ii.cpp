class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int NEG=-1e9;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n,NEG)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        int j1 = 0, j2 = n - 1;
        for (int i = 1; i < m; i++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    int maxi =NEG;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int J1 = j1 + d1;
                            int J2 = j2 + d2;
                            if (J1 < 0 || J2 < 0 || J1 >= n || J2 >= n)
                                continue;
                            maxi = max(maxi, dp[i - 1][J1][J2]);
                        }
                    }
                    if(maxi==NEG) continue;
                    if (j1 == j2)
                        dp[i][j1][j2]= grid[i][j1]+maxi;
                    else
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2]+maxi;

                        
                }
            }
        }
        int ans=NEG;
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                ans=max(ans,dp[m-1][j1][j2]);
            }
        }
  
        return ans;
    }
};