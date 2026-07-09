class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> umap;
       vector<int> a(n);
       for(int i=0;i<n;i++) a[i]=nums[i]%k;
        long long  pref=0;
        umap[0]=-1;
        for(int r=0;r<n;r++){
            pref+=a[r];
            if(umap.count(pref%k)){
                if(r-umap[pref%k]>=2)return true;
            }
            else
            umap[pref%k]=r;
        }
        return false;
    }
};