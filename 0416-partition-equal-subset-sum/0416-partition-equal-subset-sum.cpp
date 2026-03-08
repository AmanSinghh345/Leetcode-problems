class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int target=total/2;
        int n=nums.size();
        if(total&1) return false;
        vector<bool> dp(target+1);
        dp[0]=true;
        for(int x:nums)
        {
            for(int sum=target;sum>=x;sum--)
            {
                dp[sum]=(dp[sum]or dp[sum-x]);
            }
        }
        return dp[target];
    }
};