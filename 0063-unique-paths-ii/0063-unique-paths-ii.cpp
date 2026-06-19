class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]) return 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,0);
        dp[0]=1;
        for(int j=1;j<n;j++){
            if(grid[0][j]==1) dp[j]=0;
            else
            dp[j]=dp[j-1];
        }
        for(int i=1;i<m;i++){
            if(grid[i][0]) dp[0]=0;
            for(int j=1;j<n;j++){
                if(grid[i][j]==1) dp[j]=0;
                else dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};