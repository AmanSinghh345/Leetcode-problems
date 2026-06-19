class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+triangle[i][0];
        }
        for(int i=1;i<m;i++){

            for(int j=1;j<=i;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for(int x:dp[m-1]){
            ans=min(ans,x);
        }
        return ans;
    }
};