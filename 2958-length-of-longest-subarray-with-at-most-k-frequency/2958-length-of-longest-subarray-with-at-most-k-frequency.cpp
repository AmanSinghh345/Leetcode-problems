class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> umap;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            umap[nums[r]]++;
            while(umap[nums[r]]>k){
                umap[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};