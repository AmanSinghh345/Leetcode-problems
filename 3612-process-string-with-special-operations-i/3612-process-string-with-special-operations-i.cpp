class Solution {
public:
    string processStr(string s) {
        string ans="";
        cout<<ans<<endl;
        for(char c:s){
            if(c=='*' && !ans.empty()) ans.pop_back();
            else if(c=='#' ) ans=ans+ans;
            else if(c=='%') reverse(ans.begin(),ans.end());
            else if(c>='a' && c<='z') ans+=c;
            cout<<ans<<endl;
        }
        return ans;
    }
};