class Solution {
public:
     int dp[302][5002];
    int find(int i,vector<int>& coins,int amount){
        if(i>=coins.size()) return 0;
        if(amount==0) return 1;
    
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=0;
        if(coins[i]<=amount){
            pick=find(i,coins,amount-coins[i]);
        }
        int notpick=find(i+1,coins,amount);
        return dp[i][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return find(0,coins,amount);
    }
};