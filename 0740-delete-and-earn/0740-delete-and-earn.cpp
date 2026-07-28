class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int x:nums) umap[x]++;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        int m=temp.size();
        int maxEle=temp[m-1];
        vector<int> dp(maxEle+1,0);
        for(int i=1;i<=maxEle;i++){
            if(i==1){
                dp[i]=i*umap[i];
            }
            else{
               
             dp[i]=max(dp[i-1],dp[i-2]+i*umap[i]);
                
            }
        }
        return dp[maxEle];
    }
};