class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            int ind=val-1;
            if(nums[ind]<0) {
                //already marked 
                ans.push_back(val);
            }
            else nums[ind]=-nums[ind];
        }
        return ans;
    }
};