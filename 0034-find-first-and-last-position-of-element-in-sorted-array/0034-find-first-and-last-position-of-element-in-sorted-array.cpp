class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        int f=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                f=mid;
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        l=0,h=n-1;
        int s=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                s=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(f==-1 or s==-1) return {-1,-1};
        return {f,s};
    }
};