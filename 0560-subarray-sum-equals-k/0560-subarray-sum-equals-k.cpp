class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int pref=0;
        int cnt=0;
        unordered_map<int,int> umap;
        umap[0]=1;
        for(int x:nums){
            pref+=x;
            if(umap.count(pref-x)) cnt+=umap[pref-k];
            umap[pref]++;

        }
        return cnt;
    }
};