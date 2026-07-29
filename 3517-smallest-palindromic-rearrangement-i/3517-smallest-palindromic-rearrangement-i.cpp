class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char c: s) freq[c-'a']++;
        bool found=false;
        char ch;
        string left="",right="";
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(freq[i]&1){
                found=true;
                ch=('a'+i);
            }
            int half=freq[i]/2;
            left=left+string(half,('a'+i));
            right=string(half,('a'+i))+right;
        }
        if(found) left+=ch;
        return left+right;
    }
};