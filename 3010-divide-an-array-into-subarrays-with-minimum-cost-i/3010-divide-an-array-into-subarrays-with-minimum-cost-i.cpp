class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int fmin=INT_MAX,smin=INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<fmin){
                smin=fmin;
                fmin=nums[i];
            }
            else if(nums[i]>=fmin and smin>nums[i])
            {
                smin=nums[i];
            }
        }
        ans+=(fmin+smin);
        return ans;
    }
};