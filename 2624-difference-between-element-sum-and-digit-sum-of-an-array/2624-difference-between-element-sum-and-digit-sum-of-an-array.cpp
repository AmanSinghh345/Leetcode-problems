class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int digitSum=0;
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           while(nums[i]>0){
            int digit=nums[i]%10;
            digitSum+=digit;
            nums[i]/=10;
           }
        }
        return abs(sum-digitSum);
    }
};