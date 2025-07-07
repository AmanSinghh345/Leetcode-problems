class Solution {
public:
    int findVal(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
            int n=s.size();
            int ans=0;
            for(int i=0;i<n;){
                if(i<n-1 and findVal(s[i])<findVal(s[i+1])){
                        ans+=(findVal(s[i+1])-findVal(s[i]));
                        i+=2;
                }
                else {ans+=findVal(s[i]); i++;}
            }
            return ans;
    }
};