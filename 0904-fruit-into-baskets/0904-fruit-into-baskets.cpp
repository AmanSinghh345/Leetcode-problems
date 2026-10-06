class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> umap;
        int n=fruits.size();
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            umap[fruits[r]]++;
            while(l<r && umap.size()>2){
                umap[fruits[l]]--;
                if(umap[fruits[l]]==0) umap.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};