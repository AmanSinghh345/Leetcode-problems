class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<unsigned int > dp(n+1,0);

            dp[n]=1;
        

        for(int i=m-1;i>=0;i--){
            vector<unsigned int> curr=dp;
            for(int j=n-1;j>=0;j--){
                if(s[i]==t[j]){
                    curr[j]=dp[j+1]+dp[j];
                }
                else curr[j]=dp[j];
            }
            dp=curr;
        }
        return (int)dp[0];
    }
};