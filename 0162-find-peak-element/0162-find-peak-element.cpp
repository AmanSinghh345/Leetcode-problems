class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid<n-1 and nums[mid]<nums[mid+1]){
                l=mid+1;
                
            }
            else h=mid-1;
        }
        return l;
    }
};