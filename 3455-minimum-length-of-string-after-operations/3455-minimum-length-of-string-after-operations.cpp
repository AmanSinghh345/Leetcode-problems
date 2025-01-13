class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(n<2) return n;
        vector<int > freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]<3) {ans+=freq[i]; continue;}
            if(freq[i]%2==0) ans+=2;
            else ans+=1;
             
        }
        return ans;
    }
};
