class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp (n,vector<vector<int>> (2,vector<int> (3,-1)));
        int dp[1000001][2][3];
        memset(dp,-1,sizeof(dp));
        return f(0,1,2,prices,dp);
    }
    int f(int i,int buy,int cap,vector<int>& prices,int dp[][2][3])
    {
        if(i==prices.size()) return 0;
        if(cap==0) return 0;
        int profit=0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy)
        {
            profit=max(-prices[i]+f(i+1,0,cap,prices,dp),0+f(i+1,1,cap,prices,dp));
        }
        else
        {
            profit=max(prices[i]+f(i+1,1,cap-1,prices,dp),0+f(i+1,0,cap,prices,dp));
        }
        return dp[i][buy][cap]=profit;
    }
};