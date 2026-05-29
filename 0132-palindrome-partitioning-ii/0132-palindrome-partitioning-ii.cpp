class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> isPallin(n,vector<bool> (n,false));

        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len<=2) isPallin[i][j]=true;
                    else{
                        isPallin[i][j]=isPallin[i+1][j-1];
                    }
                }
            }
        }

        vector<int> dp(n,INT_MAX);

        for(int i=0;i<n;i++){
            if(isPallin[0][i]){
                dp[i]=0;
            }
            else{
                for(int k=1;k<=i;k++){
                    if(isPallin[k][i] && dp[k-1]!=INT_MAX){
                        dp[i]=min(dp[i],dp[k-1]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};