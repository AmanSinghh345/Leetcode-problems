class Solution {
public:
    int find(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        //pick
        int pick=nums[i]+find(i+2,nums,dp);
        //not pick
        int notpick=find(i+1,nums,dp);
        return dp[i]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return find(0,nums,dp);
    }
};