class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int countNegatives=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) return 0;
            else if(nums[i]<0) countNegatives++;  
        }  
        if(countNegatives%2==0) return 1;
        else return -1;
    }
};