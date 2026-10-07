class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int x:nums) umap[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto [x,cnt]:umap){
            pq.push({cnt,x});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};