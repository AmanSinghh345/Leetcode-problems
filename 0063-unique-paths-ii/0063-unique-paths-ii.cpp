class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // vector<vector<int>> dp(m+1,vector<int> (n+1,0));
         if(obstacleGrid[0][0]==1) return 0;
        // dp[1][1]=1;

        vector<int> prev(n),curr(n);
        int j=0;
        for( j=0;j<n;j++)
        {
            if(obstacleGrid[0][j]==1) {prev[j]=0; break;}
            else prev[j]=1;
        }
        for(int k=j+1;k<n;k++)
            prev[k]=0;
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]==1 or obstacleGrid[i-1][0]) curr[0]=0;
            else curr[0]=prev[0];
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1 or (obstacleGrid[i][j-1] and obstacleGrid[i-1][j]==1)) curr[j]=0;
                else
                {
                    curr[j]=prev[j]+curr[j-1];
                }
                
            }
            prev=curr;
        }
      
        return prev[n-1];
    }
};