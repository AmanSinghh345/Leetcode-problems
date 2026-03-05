class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int cntZero=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) cntZero++;
            else prod*=nums[i];
        }
        if(cntZero>1) return vector<int>(n,0);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(cntZero==1)
            {
                if(nums[i]!=0)
                {
                    ans[i]=0;
                }
                else {
                    ans[i]=prod;
                }
            }
            else{
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};