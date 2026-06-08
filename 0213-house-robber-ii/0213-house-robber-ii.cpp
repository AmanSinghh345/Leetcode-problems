class Solution {
public:
    int find(int start,int end,vector<int>& nums,vector<int>& dp){
        if(start>end) return 0;
        if(dp[start]!=-1) return dp[start];
        //pick
        int pick=nums[start]+find(start+2,end,nums,dp);
        //notpick
        int notpick=find(start+1,end,nums,dp);
        return dp[start]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int s1=0,s2=1,e1=n-2,e2=n-1;
        vector<int> dp(n,-1);
        int x=find(s1,e1,nums,dp);
        dp.assign(n,-1);
        int y=find(s2,e2,nums,dp);
        return max(x,y);
    }
};