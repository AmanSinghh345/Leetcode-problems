class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);
        int val=1;
        for(int i=0;i<n;i++)
        {
            pref[i]=val*nums[i];
            val=pref[i];
        }
        val=1;
        vector<int> suff(n);
        for(int i=n-1;i>=0;i--)
        {
            suff[i]=val*nums[i];
            val=suff[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans[i]=suff[1];
            }
            else if(i==n-1)
            {
                ans[i]=pref[n-2];
            }
            else {
                ans[i]=pref[i-1]*suff[i+1];
            }
        }
        return ans;
    }
};