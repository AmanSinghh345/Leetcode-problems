class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> path(n,0);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            path[i]+=maxi;
        }
        int mini=nums[n-1];
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            path[i]-=mini;
        }
        for(int i=0;i<n;i++){
            if(path[i]<=k) return i;
        }
        return -1;
    }
};