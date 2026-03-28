class Solution {
public:
    int f(int n,vector<int>& dp){
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=dp[1]=1;
        f(n,dp);
        return dp[n];
    }
};