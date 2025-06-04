class Solution {
public:
    string find(string s){
        int l=0;
        int r=1;
        int n=s.size();
        while(r<=n-1){
            int pos=0;
            while(r+pos<n and s[l+pos]==s[r+pos]){
                pos++;
            }
            if(r+pos<n and s[l+pos]<s[r+pos]){
                int temp=l;
                l=r;
                r=max(r+1,temp+pos+1);
            }
            else {
                r+=pos+1;
            }
        }
        return s.substr(l,n-l);
    }
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1 ) return word;
        string end=find(word);
        int m=end.size();
        return end.substr(0, min(n-numFriends+1,m));
        

    }
};