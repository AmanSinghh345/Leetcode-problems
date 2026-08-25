class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int x:nums) umap[x]++;
        
        for(int i=1;;i++){
                 int val=k*i; 
            if(umap.count(val)==0) return val;
       
        }
        return -1;
    }
};