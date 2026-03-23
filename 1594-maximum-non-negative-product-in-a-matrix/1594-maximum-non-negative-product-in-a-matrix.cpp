class Solution {
public:
    int mod = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector< pair<long long ,long long > > dp(n);

        dp[0]={grid[0][0],grid[0][0]};

        for(int j=1;j<n;j++){
            long long  val=dp[j-1].first*grid[0][j];
            dp[j]={val,val};
        }

        for(int i=1;i<m;i++){
            long long val=dp[0].first*grid[i][0];
            dp[0]={val,val};
            for(int j=1;j<n;j++){

                long long x=grid[i][j];
                vector<long long > candidates={
                    x*dp[j].first,
                    x*dp[j].second,
                    x*dp[j-1].first,
                    x*dp[j-1].second
                };
                long long maxi=*max_element(candidates.begin(),candidates.end());
                long long mini=*min_element(candidates.begin(),candidates.end());

                dp[j]={maxi,mini};
            }
        }
        return dp[n-1].first<0? -1 : dp[n-1].first%mod;
    }
};