class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted=arr;
        int n=arr.size();
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> umap;
        for(int x:sorted){
            if(umap.count(x)==0) umap[x]=(int)umap.size()+1;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=umap[arr[i]];
        }
        return ans;
    }
};