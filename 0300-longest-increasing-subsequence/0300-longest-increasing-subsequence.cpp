class Solution {
public:
    int find(int i,int prevInd,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i][prevInd+1]!=-1) return dp[i][prevInd+1];
        int take=0;
        if(prevInd==-1 or nums[i]>nums[prevInd]) 
        {
            take=1+find(i+1,i,nums,dp);
        }
        int nottake=0+find(i+1,prevInd,nums,dp);
        return dp[i][prevInd+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return find(0,-1,nums,dp);
    }
};