class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        bool o=true,e=true;
        int so=INT_MAX;
        int se=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]&1) so=min(so,nums[i]);
            else se=min(se,nums[i]);
        }

        for(int i=0;i<n;i++){
            if(nums[i]%2==0 and nums[i]<=so){
                o=false;
                continue;
            }
            if(nums[i]%2!=0 and nums[i]<=so) e=false;
            
        }
       return o||e;
    }
};