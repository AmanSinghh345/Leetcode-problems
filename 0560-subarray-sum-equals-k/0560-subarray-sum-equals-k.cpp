class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> umap;
        umap[0]=1;
        long long pref=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            if(umap.count(pref-k)) cnt+=umap[pref-k];
            umap[pref]++;
        }
        return cnt;
    }
};