class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        
        for(int x:nums) umap[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq ; // maximum by default
        for(auto it:umap)
        {
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};