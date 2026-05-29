class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,INT_MAX);
        for(int i=0;i<n;i++){

            for(int len=0 ; i-len>=0 && i+len<n && s[i-len]==s[i+len] ; len++ )
            {
                int l=i-len;
                int r=i+len;
                dp[r]=(l==0)?0:min(dp[r],dp[l-1]+1);
            }
            for(int len=0;i-len>=0 && i+len+1<n && s[i-len]==s[i+len+1];len++){
                int l=i-len;
                int r=i+len+1;
                dp[r]=(l==0)?0:min(dp[r],dp[l-1]+1);
            }


        }
        return dp[n-1];
    }
};