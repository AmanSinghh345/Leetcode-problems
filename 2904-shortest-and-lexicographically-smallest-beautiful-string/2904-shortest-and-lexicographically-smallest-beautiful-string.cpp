class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        int n=s.size();
        int l=0;
        int cnt=0;
        
        for(int r=0;r<n;r++){
            if(s[r]=='1') cnt++;
            while(l<=r and s[l]=='0'){
                    l++;
            }
         
            if(cnt==k){
                if(ans.empty()) ans=s.substr(l,r-l+1);
             
                else  if(ans.size()>s.substr(l,r-l+1).size()) ans=s.substr(l,r-l+1);
                else if(ans.size()==s.substr(l,r-l+1).size()) ans=min(ans,s.substr(l,r-l+1));
                if(s[l]=='1') cnt--;
                l++;

            }
            cout<<ans<<endl;
           
        }
       
        return ans;
    }
};