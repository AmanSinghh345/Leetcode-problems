class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++){
            dp[i].resize(i+1,INT_MAX);
        }

        for(int j=0;j<triangle[m-1].size();j++){
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};