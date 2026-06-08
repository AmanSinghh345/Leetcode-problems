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
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+(i-2>=0?dp[i-2]:0));
        }
        return dp[n-1];
    }
};