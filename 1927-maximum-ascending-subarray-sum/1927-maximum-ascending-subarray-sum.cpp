class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int maxi=nums[0];
        int maxele=*max(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){ sum+=nums[i];
            maxi=max(maxi,sum);}
            else sum=nums[i];
        }
      
        return maxi;
    }
};