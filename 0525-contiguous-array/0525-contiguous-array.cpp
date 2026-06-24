class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        umap[0]=0;
        int maxLen=0;
        int pref=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) pref+=1;
            else pref-=1;
            if(umap.count(pref)){
                int len=(i+1)-umap[pref];
                maxLen=max(maxLen,len);
            }
            else{
                umap[pref]=i+1;
            }

        }
       
        return maxLen;
    }
};