class Solution {
public:
    long long  f(int i,int j,vector<int>& cuts,vector<vector<long long>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long  mini=LLONG_MAX;
        long long  cost;
        for(int ind=i;ind<=j;ind++){
            cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<long long >> dp(m,vector<long long > (m,-1));
        return (int)f(1,(int)cuts.size()-2,cuts,dp);
    }
};