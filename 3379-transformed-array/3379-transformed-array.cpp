class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {   
            int ind;
            if(nums[i]<0)
            {
               ind=(i+nums[i]%n+n)%n;
            }
            else ind=(i+nums[i])%n;
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};