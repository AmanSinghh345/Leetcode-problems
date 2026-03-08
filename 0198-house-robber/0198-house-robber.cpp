class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0,prev1=0;
        for(auto x:nums)
        {
            int curr=max(prev1,x+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};