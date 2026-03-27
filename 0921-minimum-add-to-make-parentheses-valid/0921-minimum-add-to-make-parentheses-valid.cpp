class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        if(n==0) return 0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else{
                if(cnt>0) cnt--;
                else  ans++;
            }
        }
        return abs(cnt)+ans;
    }
};