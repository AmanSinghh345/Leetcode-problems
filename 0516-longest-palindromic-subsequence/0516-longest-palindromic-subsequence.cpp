class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size();
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curr=prev;
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]) curr[j]=prev[j-1]+1;
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
};