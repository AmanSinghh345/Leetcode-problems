class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int j=1;
            while(i-j*j>=0){
                if(dp[i-j*j]!=INT_MAX) dp[i]=min(dp[i],1+dp[i-j*j]);
                j++;
            }
        }
        return dp[n];
    }
};