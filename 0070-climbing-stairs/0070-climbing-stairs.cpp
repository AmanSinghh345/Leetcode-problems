class Solution {
public:
    int recurr(int n,vector<int>& dp){
        if(n==0 or n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int a=recurr(n-1,dp);
        int b=recurr(n-2,dp);
        return dp[n]=a+b;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
       int ans = recurr(n,dp);
        return ans;
    }
};