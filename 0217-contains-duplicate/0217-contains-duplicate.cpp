class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++)
        {
            if(umap.find(nums[i])!=umap.end())
            {
                return true;
            }
            umap[nums[i]]=1;
        }
        return false;
    }
};