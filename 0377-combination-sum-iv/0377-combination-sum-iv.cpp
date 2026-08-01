class Solution {
public:
    int find(int target,vector<int>& nums,vector<int>& dp){
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];

        int take=0;
        for(int &x : nums){
            take+=find(target-x,nums,dp);
        }
        return dp[target]=take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        dp[0]=1;
        find(target,nums,dp);
        return dp[target];
    }
};