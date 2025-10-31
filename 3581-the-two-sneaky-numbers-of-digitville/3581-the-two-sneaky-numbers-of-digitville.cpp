class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
            if(umap[nums[i]]==2) ans.push_back(nums[i]);
        }
        return ans;
    }
};