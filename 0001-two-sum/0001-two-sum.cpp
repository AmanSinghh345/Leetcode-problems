class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(umap.count(target-x)){
                return {i,umap[target-x]};
            }
            umap[x]=i;
        }
        return {-1,-1};
    }
};