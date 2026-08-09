class Solution {
public:
    int find(int ind,int M,int n,vector<int>& suffix,vector<vector<int>> & dp){
         if(ind>=n) return 0;
         if(ind+2*M>=n) return suffix[ind];
         if(dp[ind][M]!=-1) return dp[ind][M];


         int maxi=0;
         for(int i=0;i<2*M;i++){
           
             
            int oppScore= find(ind+i+1,max(M,i+1),n,suffix,dp);
            int myscore=suffix[ind]-oppScore;
            maxi=max(maxi,myscore);
         }
       return  dp[ind][M]=maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> suffix(n,0);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--) suffix[i]=suffix[i+1]+piles[i]; 
   
        vector<vector<int>> dp(n,vector<int> (n+1,-1));

        for(int i=n-1;i>=0;i--){
            for(int M=1;M<=n;M++){
                if(i+2*M>=n) dp[i][M]=suffix[i];
                else {
                    int maxi=0;
                    for(int x=1;x<=2*M;x++){
                        int oppscore=dp[i+x][max(M,x)];
                        int myscore=suffix[i]-oppscore;
                        maxi=max(maxi,myscore);
                    }
                     dp[i][M]=maxi;
                }
               
            }
        }
        return dp[0][1];
    }
};