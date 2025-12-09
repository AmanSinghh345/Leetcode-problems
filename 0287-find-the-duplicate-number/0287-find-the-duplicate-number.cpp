class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
            if(umap[nums[i]]==2) return nums[i];
        }
        return -1;
    }
};