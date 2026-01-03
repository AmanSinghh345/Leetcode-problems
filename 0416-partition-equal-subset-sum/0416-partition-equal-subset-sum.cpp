class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total&1) return false;
        int req=total/2;
        vector<bool> dp(req+1,false);
        dp[0]=true;
        for(int x:nums)
        {
            for(int target=req;target>=x;target--)
            {
                dp[target]=dp[target]||dp[target-x];
            }
        }
        return dp[req];
    }
};