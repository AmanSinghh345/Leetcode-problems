class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp (n,vector<vector<int>> (2,vector<int> (3,-1)));
        int dp[1000001][2][3];
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int cap=1;cap<3;cap++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
                    }
                    else 
                    {
                        profit=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
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