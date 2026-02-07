class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> pref(n,0),suff(n,0);
      
        for(int i=1;i<n;i++)
        {
            if(s[i-1]=='1')
            {
                pref[i]=pref[i-1]+1;
            }
            else pref[i]=pref[i-1];
        }
       
        for(int i=n-2;i>=0;i--)
        {
            if(s[i+1]=='0') {
                suff[i]=suff[i+1]+1;
            }
            else suff[i]=suff[i+1];
        }
        int mini=n;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,pref[i]+suff[i]);
        }
        return mini;
    }
};