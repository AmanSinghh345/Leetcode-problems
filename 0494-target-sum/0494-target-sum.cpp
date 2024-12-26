class Solution {
public:
    int recursion(int index,int sum,int target,vector<int>& nums){
        if(index==nums.size()) return (sum==target)?1:0;
        int left=recursion(index+1,sum+nums[index],target,nums);
        int right=recursion(index+1,sum-nums[index],target,nums);
        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int index=0;
        int sum=0;
       return recursion(index,sum,target,nums);
    }
};