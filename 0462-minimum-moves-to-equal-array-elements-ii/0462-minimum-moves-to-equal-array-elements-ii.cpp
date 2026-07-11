class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
        int median=nums[mid];
        int diff=0;
        for(int x:nums) diff+=(abs(median-x));
        return diff;
    }
};