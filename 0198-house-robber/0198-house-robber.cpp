class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>& dp)
    {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+f(i+2,nums,dp);
        int notTake=0+f(i+1,nums,dp);
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int take=nums[i];
            if(i>1)
            {
                take+=dp[i-2];
            }
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[nums.size()-1];
    }
};