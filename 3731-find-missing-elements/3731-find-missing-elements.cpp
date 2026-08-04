class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=0;
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int x:nums) umap[x]++;
        for(int i=nums[0];i<=nums[nums.size()-1];i++){
            if(umap.count(i)==0) ans.push_back(i);
        }
        return ans;
    }
};