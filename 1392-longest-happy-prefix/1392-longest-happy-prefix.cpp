class Solution {
public:
    vector<int> kmp(string s){
        int n=s.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int prev_ind=lps[i-1];
            while(prev_ind>0 and s[i]!=s[prev_ind]) prev_ind=lps[prev_ind-1];
            if(s[i]==s[prev_ind]) prev_ind++;
            lps[i]=prev_ind;
        }
        return lps;
    }
    string longestPrefix(string s) {
        
        vector<int> lps=kmp(s);
        int len=lps[(int)lps.size()-1];
        return s.substr(0,len);
    }
};