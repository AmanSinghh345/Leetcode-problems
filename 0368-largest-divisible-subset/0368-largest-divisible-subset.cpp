class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //Longest divisble susequence 
        sort(nums.begin(),nums.end());

        int n=nums.size();

        vector<int> dp(n,1);
        vector<int> par(n,-1);
        int maxLen=1;
        int maxInd=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        int i;
        for(i=maxInd;i!=-1;i=par[i]){
            ans.push_back(nums[i]);
        }
        reverse(nums.begin(),nums.end());
        return ans;
    }
};