class Solution {
public:
    int expand(string s,int l,int r){
        int cnt=0;
        while(l>=0 and r<s.size() && s[l]==s[r])
        {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
             
             ans+=expand(s,i,i);
              
              ans+=expand(s,i,i+1);
        }
        return ans;
    }
};