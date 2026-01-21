class Solution {
public:
    int vowelConsonantScore(string s) {
        int n=s.size();
        int c=0,v=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u') v++;
            else {if(s[i]>='a' and s[i]<='z') c++;}
        }
       
        if(c==0) return 0;
        return v/c;
    }
};