class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++){
            int icnt=1;
            int dcnt=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j-1]>nums[j]){
                    dcnt++;
                    maxi=max(maxi,dcnt);
                }
                else dcnt=0;
                if(nums[j-1]<nums[j]){
                    icnt++;
                    maxi=max(maxi,icnt);
                }
                else icnt=0;
                
            }
        }
        return maxi;
    }
};