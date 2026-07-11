class Solution {
public:
    int minMoves(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int l=0,r=n-1;
       int add=0;
       while(l<r){
           int diff=nums[r]+add-(nums[l]+add);
            add+=diff;
            r--;
       }
       return add;
    }
};