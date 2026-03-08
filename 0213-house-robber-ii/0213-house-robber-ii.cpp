class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev1=0,prev2=0;
        for(int i=0;i<=n-2;i++)
        {
            int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        int a=prev1;
        prev1=0;
        prev2=0;
        for(int i=1;i<n;i++)
        {
              int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        int b=prev1;
        return max(a,b);
    }
};