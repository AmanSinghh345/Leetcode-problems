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

        int p2=0,p1=0;
        for(int i=0;i<n;i++){
            int curr=max(p1,p2+nums[i]);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};