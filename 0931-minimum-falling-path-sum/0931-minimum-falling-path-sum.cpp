class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       vector<vector<int>> dp(m+1,vector<int> (n+1,1e9));

        for(int j=1;j<=n;j++)
        {
            dp[1][j]=matrix[0][j-1];
        }

        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==1)
                {
                    dp[i][j]=matrix[i-1][j-1]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n)
                {
                    dp[i][j]=matrix[i-1][j-1]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else {
                    dp[i][j]=matrix[i-1][j-1]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                }
            }
        }
        int ans=INT_MAX;
        for(int j=1;j<=n;j++)
        {
            ans=min(ans,dp[m][j]);
        }
        return ans;
    }
};