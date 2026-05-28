class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<unsigned int > dp(n+1,0);

            dp[n]=1;
        

        for(int i=m-1;i>=0;i--){
                dp[n]=1;
            for(int j=0;j<n;j++){
                if(s[i]==t[j]){
                    dp[j]+=dp[j+1];
                }
                
            }
            
        }
        return (int)dp[0];
    }
};