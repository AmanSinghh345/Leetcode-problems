class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
       int maxi=INT_MIN;
        int diff;
        int ans;
        for(int i=0;i<n;i++){
            
            diff=abs(nums[i]-0);
               

           
            if(diff<mini )
            ans=nums[i];
            else if(diff==mini)
            {
                ans=max(ans,nums[i]);
            }
            
           mini=min(mini,diff);
           
        }
        return ans;
    }
};