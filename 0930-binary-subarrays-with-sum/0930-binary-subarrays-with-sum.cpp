class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0){
            return atmost(nums,0);
        }
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(vector<int>& nums,int k)
    {
        int n=nums.size();
        int sum=0;
        int l=0;
        int cnt=0;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(l<n and sum>k)
            {
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};