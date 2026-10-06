class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            int l=i;
            if(l>0 and nums[l]==nums[l-1]){ l++; continue;}
            int j=l+1;
            int k=n-1;
            while(j<k){
                int sum=nums[l]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[l],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(k>j && nums[k]==nums[k+1]) k--;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        return ans;
    }
};