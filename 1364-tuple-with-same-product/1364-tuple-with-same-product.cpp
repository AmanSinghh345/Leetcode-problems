class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               int   product=nums[i]*nums[j];
                umap[product]++;}
        }
        int ans=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            if(it->second>1) ans+=((it->second-1)*(it->second)*8)/2;

        }
        return ans;
    }
};