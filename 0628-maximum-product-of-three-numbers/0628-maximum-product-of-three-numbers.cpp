class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==3) return nums[0]*nums[1]*nums[2];
        if(nums[0]>0) return nums[n-1]*nums[n-2]*nums[n-3];
        else {
            return max(nums[0]*nums[1]*nums[n-1],nums[n-3]*nums[n-2]*nums[n-1]);
        }
        return -1;
    }
};