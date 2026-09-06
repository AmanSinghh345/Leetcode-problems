class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp ){
        if(i==m-1  ) return grid[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int south=f(i+1,j,m,n,grid,dp);
        int southeast=f(i+1,j+1,m,n,grid,dp);
    
   return  dp[i][j]=(grid[i][j]+min(south,southeast));

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        return f(0,0,m,n,triangle,dp);
    }
};