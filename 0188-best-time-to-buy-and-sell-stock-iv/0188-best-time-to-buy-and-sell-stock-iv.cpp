class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        // vector<vector<vector<int>>> dp (n,vector<vector<int>> (2,vector<int> (3,-1)));
        // int dp[1000001][2][3];
        // memset(dp,0,sizeof(dp));
        
        vector<vector<int>> after(2,vector<int> (k+1,0));
        vector<vector<int>> curr(2,vector<int> (k+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int cap=1;cap<k+1;cap++)
                {       if(buy)
                        curr[buy][cap]=max(-prices[i]+after[0][cap],0+after[1][cap]);
                    else
                        curr[buy][cap]=max(prices[i]+after[1][cap-1],0+after[0][cap]);
                    
                   
                }
            }
            after=curr;
        }
        return after[1][k];
    }
};