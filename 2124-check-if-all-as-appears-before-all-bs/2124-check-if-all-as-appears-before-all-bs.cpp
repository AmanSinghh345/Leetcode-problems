class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int l=-1,r=n;
        for(int i=0;i<n;i++)
        {   

            if(s[i]=='b') {
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')
            {
                r=i;
                break;
            }
        }
        if(l==-1 or r==n or r<l) return 1;
        return false;
      
    }
};