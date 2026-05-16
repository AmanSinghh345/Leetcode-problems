class Solution {
public:
    bool left(int l,int r,vector<int>& nums){
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<nums[r]) return true;
            if(nums[mid]>nums[r]) return false;
            else{
                return left(l,mid,nums)||left(mid+1,r,nums);
            }
        }
        return false;
    }
    int findMin(vector<int>& nums) {
         int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==nums[r]){
                if(left(l,mid,nums)){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            } 
            else if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        int ans=min(nums[0],nums[l]);
        return ans;
    }
};