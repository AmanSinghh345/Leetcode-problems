class Solution {
public:
    vector<int> kmp(string s){
        int n=s.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int prev_ind=lps[i-1];
            while(prev_ind>0 && s[i]!=s[prev_ind]){
                prev_ind=lps[prev_ind-1];
            }
            if(s[i]==s[prev_ind]) prev_ind++;
            lps[i]=prev_ind;
        }
        return lps;

    }
    int strStr(string haystack, string needle) {
        string s=needle+"#"+haystack;
        vector<int> lps=kmp(s);
        for(int i=2*needle.size();i<lps.size();i++){
            if(lps[i]==needle.size()) {
                int ans=i-2*needle.size();
                return ans;
            }
        }
        return -1;
    }
};