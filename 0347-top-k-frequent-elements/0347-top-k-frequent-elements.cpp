class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int x:nums) umap[x]++;

        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto it:umap)
        {
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n;i>=0 and ans.size()<k ;i--)
        {
            for(int j=0;j<bucket[i].size();j++)
            {
                ans.push_back(bucket[i][j]);
                if(ans.size()>=k) break;
            }
        }
        return ans;
    }
};