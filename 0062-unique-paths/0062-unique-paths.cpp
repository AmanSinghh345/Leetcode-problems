class Solution {
public:
    int recurr(int i,int j,vector<vector<int>>& dp)
    {
        if(i==0 and j==0) return 1;
        if(i<0 or j<0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=recurr(i-1,j,dp);
        int left=recurr(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans=recurr(m-1,n-1,dp);
        return ans;
    }
};