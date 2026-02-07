class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> suffA(n+1,0),prefB(n+1,0);
        for(int i=0;i<n;i++)
        {
           
           if(s[i]=='b')
            prefB[i+1]=prefB[i]+1;
            else prefB[i+1]=prefB[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')
            {
                suffA[i]=suffA[i+1]+1;
            }
            else suffA[i]=suffA[i+1];
        }

        int mini=n;
        for(int i=0;i<=n;i++)
        {
            mini=min(mini,prefB[i]+suffA[i]);
        }
        return mini;
    }
};