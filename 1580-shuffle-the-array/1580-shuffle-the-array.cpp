class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int o) {
       vector<int> ans(nums.size());
       int n=nums.size();
       int j=1;
       for(int i=n/2;i<n;i++){
         
        ans[j]=nums[i];
        j+=2;
       }
       int k=0;
       for(int i=0;i<n/2;i++){
        ans[k]=nums[i];
        k+=2;
       }
       return ans;
    }
};