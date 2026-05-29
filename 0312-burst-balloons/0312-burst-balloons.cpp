class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int val=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
            maxi=max(maxi,val);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
    


        for(int len=1;len<=n-2;len++){
            for(int i=1;i<=n-2-len+1;i++){
                int j=i+len-1;
                if(i>j) continue;
                int currMax=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int val=nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                    currMax=max(currMax,val);
                }
                dp[i][j]=currMax;
            }
        }
        return dp[1][n-2];
    }
};