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
    int mod=1e8+7;
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector< unsigned long long > dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if((i-nums[j])>=0) 
                dp[i]+=dp[i-nums[j]];
               
            }
        }
        return dp[target];
    }
};