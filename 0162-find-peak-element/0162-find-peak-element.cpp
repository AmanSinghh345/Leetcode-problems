class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int ind;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                ind=i;
            }
        }
        return ind;
    }
};