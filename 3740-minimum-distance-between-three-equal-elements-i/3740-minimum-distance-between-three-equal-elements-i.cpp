class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<n;i++){
            umap[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto & it : umap){
            auto &arr=it.second;
            for(int i=0;i+2<arr.size();i++){
                ans=min(ans,2*(arr[i+2]-arr[i]));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};