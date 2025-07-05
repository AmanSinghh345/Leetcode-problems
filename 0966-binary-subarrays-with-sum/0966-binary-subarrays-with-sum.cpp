class Solution {
public:

    int find(vector<int>& nums,int goal){  //TO Get Number of Subarray with sum <=k
            int n=nums.size();
            int l=0,r=0;
            int sum=0,res=0;
            int k=goal;
            if(goal<0) return 0;
            while(r<n){
                sum+=nums[r];
                while(l<n and sum>goal){
                    sum-=nums[l];
                    l++;
                }
                res+=(r-l+1);
                r++;
            }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums,goal) - find(nums,goal-1);
    }
};