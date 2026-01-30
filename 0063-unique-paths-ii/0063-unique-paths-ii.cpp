class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<int> prev(n), curr(n);
        if(obstacleGrid[0][0]==1) return 0;
        prev[0]=1;
        for(int j=1;j<n;j++)
        {   if(j>0 and prev[j-1]==0) {prev[j]=0; continue;}
            if(obstacleGrid[0][j]==1) prev[j]=0;
            else {  prev[j]=prev[j-1];}
        }

        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]==1) curr[0]=0;
            else curr[0]=prev[0];
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1) curr[j]=0;
                else curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    }
};