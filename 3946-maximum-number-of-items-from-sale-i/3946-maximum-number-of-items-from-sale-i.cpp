class Solution {
public:
    int dp[1001][1501];
    vector<int> freq;
    int mini=INT_MAX;
    int find(int i,int n,int budget,vector<vector<int>>& items){
        if(i>=n) return budget/mini;
        if(dp[i][budget]!=-1) return dp[i][budget];
        int notTake=find(i+1,n,budget,items);
        int take=0;
        if(budget>=items[i][1]){
            take=freq[i]+1+find(i+1,n,budget-items[i][1],items);
        }
        return dp[i][budget]=max(take,notTake);  
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        freq.assign(n,0);
        for(int i=0;i<n;i++){
            mini=min(mini,items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0) {
                    freq[i]++;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return find(0,n,budget,items);

    }
};