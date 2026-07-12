class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int l=0;
       int n=nums.size();
       for(int r=1;r<n;r++){
        if(nums[r]==nums[l]){
            continue;
        }
        else {
            nums[l+1]=nums[r];
            l++;
        }
       }
       return l+1;
    }
};