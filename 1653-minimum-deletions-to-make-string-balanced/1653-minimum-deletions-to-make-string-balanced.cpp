class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int b_cnt=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b') b_cnt++;
            else ans=min(ans+1,b_cnt);
        }
        return ans;
    }
};