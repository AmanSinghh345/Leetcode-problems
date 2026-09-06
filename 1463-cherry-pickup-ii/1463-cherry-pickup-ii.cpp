class Solution {
public:
    int f(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,vector<vector<vector<int>>>& vis ){
         if(j1<0 || j2<0 || j1>=n || j2>=n) return INT_MIN;
         if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
         }
         if(vis[i][j1][j2]!=-1) return dp[i][j1][j2];
         //transitions 
         int maxi=INT_MIN;
         for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                
                maxi=max(maxi,f(i+1,j1+d1,j2+d2,m,n,grid,dp,vis));
            }
         }
         vis[i][j1][j2]=1;
        if(j1==j2) return dp[i][j1][j2]= grid[i][j1]+maxi;
        return dp[i][j1][j2]= grid[i][j1]+grid[i][j2]+maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n)));
                vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,m,n,grid,dp,vis);
    }
};