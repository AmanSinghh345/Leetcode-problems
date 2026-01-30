class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int aheadNotBuy=0,aheadBuy=0;
        int currNotBuy=0,currBuy=0;

   

        for(int i=n-1;i>=0;i--)
        {
           
                    currBuy=max(-prices[i]+aheadNotBuy,0+ aheadBuy);
               
                    currNotBuy=max(prices[i]+aheadBuy,0+aheadNotBuy);
               
         aheadNotBuy=currNotBuy;
         aheadBuy=currBuy;
        }
        return aheadBuy;
    }
    int f(int i,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        // buying allowed
        // i can buy or not buy profit is both maximum
        if(buy)
        {
            profit=max(-prices[i]+f(i+1,0,prices,dp),0+f(i+1,1,prices,dp));
        }
        // buying not allowed
        // i can sell or not sell and profit is maximum of both
        else 
        {
            profit=max(prices[i]+f(i+1,1,prices,dp),0+f(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;

    }
};