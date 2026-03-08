class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> T;
        for(int i=0;i<t.size();i++)
        {
            T[t[i]]++;
        }
        unordered_map<char,int> S;
        int minlen=1e5+7;
        int start=-1;
        int l=0,r=0;
        int cnt=0;  
        while(r<s.size())
        {
            S[s[r]]++;
            if(T.find(s[r])!=T.end() and T[s[r]]==S[s[r]]) cnt++;
           
            while(cnt==T.size())    
            {
                if(r-l+1<minlen){
                   minlen=min(minlen,r-l+1);
                   start=l;
                }
                S[s[l]]--;
                if(T.find(s[l])!=T.end() and S[s[l]]<T[s[l]]) cnt--;
                l++;
            }
            r++;
        }
        if(start==-1) return "";
        else
        return s.substr(start,minlen);
    }
};