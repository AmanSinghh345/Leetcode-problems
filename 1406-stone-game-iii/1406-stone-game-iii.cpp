class Solution {
public:
    int find(int i,vector<int>& stoneValue,vector<int>& dp){
        int n=stoneValue.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int res=INT_MIN;
        int val=0;
        for(int j=i;j<=min(i+2,n-1);j++){
             val+=stoneValue[j];
            res=max(res,val-find(j+1,stoneValue,dp));
        }
        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,-1);
        find(0,stoneValue,dp);
        if(dp[0]>0) return "Alice";
        else if(dp[0]==0) return "Tie";
        return "Bob";
    }
};