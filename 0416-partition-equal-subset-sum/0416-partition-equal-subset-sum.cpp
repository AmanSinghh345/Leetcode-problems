class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int target=total/2;
        if(total&1) return false;
        vector<bool> dp(target+1,false);
        dp[0]=true; //not take case
        for(int x:nums)
        {
            for(int sum=target;sum>=x;sum--)
            {
                dp[sum]=dp[sum] || dp[sum-x];
            }
        }
        return dp[target];
    }
};