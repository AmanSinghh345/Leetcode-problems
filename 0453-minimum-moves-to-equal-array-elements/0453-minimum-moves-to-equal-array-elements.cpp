class Solution {
public:
    int minMoves(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int l=0,r=n-1;
       int diff=0;
       while(l<r){
           diff+=(nums[r]-nums[l]);
           r--;
       }
       return diff;
    }
};