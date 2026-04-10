class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<n;i++){
            umap[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it=umap.begin();it!=umap.end();it++){
            auto arr=it->second;
            if(arr.size()>=3){
                for(int i=0;i<arr.size()-2;i++){
                    for(int j=i+1;j<arr.size()-1;j++){
                        for(int k=j+1;k<arr.size();k++){
                            ans=min(ans,(abs(arr[i]-arr[j])+abs(arr[j]-arr[k])+abs(arr[i]-arr[k])));
                        }
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};