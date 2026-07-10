class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int x:nums){
            if(umap.count(x)) ans.push_back(x);
            umap[x]++;
        }
        return ans;
    }
};