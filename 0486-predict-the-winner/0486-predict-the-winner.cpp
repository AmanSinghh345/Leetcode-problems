class Solution {
public:
   int  find(int l, int r,vector<int>& nums,vector<vector<int>>& dp){
        if(l==r){
            dp[l][l]=nums[l];
            return nums[l];
        }
        if(dp[l][r]!=INT_MIN) return dp[l][r];
        int takeLeft=nums[l]-find(l+1,r,nums,dp);
        int takeRight=nums[r]-find(l,r-1,nums,dp);
        return dp[l][r]=max(takeLeft,takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        find(0,n-1,nums,dp);
        return dp[0][n-1]>=0;
    }
};