class Solution {
public:
   
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(3,0);
        for(int i=n-1;i>=0;i--){
            int res=INT_MIN;
            int val=0;
            for(int j=min(i,n-1);j<=min(i+2,n-1);j++){
                val+=stoneValue[j];
                int diff=0;
                if(j+1<n) diff=dp[j-min(i,n-1)];
                res=max(res,val-diff);
            }
            dp[2]=dp[1];
            dp[1]=dp[0];
            dp[0]=res;
        }
        if(dp[0]>0) return "Alice";
        else if(dp[0]==0) return "Tie";
        return "Bob";
    }
};