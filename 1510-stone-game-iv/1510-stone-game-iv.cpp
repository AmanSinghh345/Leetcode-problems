class Solution {
public:
   
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        for(int i=1;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                if(i-k*k>=0 and dp[i-k*k]==false){
                    dp[i]=true;
                    break;
                }
                else dp[i]=false;
            }
        }
        return dp[n];
    }
};