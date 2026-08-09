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
        return find(0,1,n,suffix,dp);
    }
};