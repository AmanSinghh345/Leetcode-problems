class Solution {
public:
    int recurr(int n ,int cnt,vector<int>& dp)
    {
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int a=recurr(n-1,cnt,dp);
        int b=recurr(n-2,cnt,dp);
        return dp[n]=a+b;
    }
    int climbStairs(int n) {

        int cnt=0;
        vector<int> dp(n+1,-1);
        int ans=recurr(n,cnt,dp);

        return ans;
         
    }
};