class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int prevDiag=0;
            for(int j=1;j<=n;j++){
                int temp=dp[j];
                if(s[i-1]==r[j-1]) dp[j]=prevDiag+1;
                else dp[j]=max(dp[j],dp[j-1]);
                prevDiag=temp;
            }
        }
        return dp[n];
    }
};