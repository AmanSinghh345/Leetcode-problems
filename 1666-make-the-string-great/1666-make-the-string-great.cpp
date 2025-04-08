class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        string ans;
        ans.push_back(s[0]);
        for(int i=1;i<n;i++){
            int length=ans.size();
            if( length>0 and (abs((ans[length-1]-'0')-(s[i]-'0')))==32 ) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
/*             DRY RUN
n=10
ans=l
i=1
length=1
if(abs((ans[0]-'0')-(e-'0')) and 1>0) 





*/