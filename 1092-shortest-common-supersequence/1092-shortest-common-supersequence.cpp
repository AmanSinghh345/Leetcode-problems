class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string s=str1;
        string r=str2;
        int m=s.size();
        int n=r.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==r[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        int i=m,j=n;
        while(i>0 and j>0)
        {
            if(s[i-1]==r[j-1])
            {
                ans+=s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=s[i-1];
                i--;
            }
            else {ans+=r[j-1];
            j--;}
        }
        while(i>0)
        {
            ans+=s[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=r[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};