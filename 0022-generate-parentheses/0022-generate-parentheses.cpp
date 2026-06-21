class Solution {
public:
    void find(string s ,int open ,int close , int n,vector<string>& ans){
        if(close>=n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            string gg=s;
            gg+='(';
            find(gg,open+1,close,n,ans);
        }
        if(close<open){
           
            string ask=s;
            ask+=')';
            find(ask,open,close+1,n,ans);
        }
    return ;
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        string s;
        find(s,open,close,n,ans);
        return ans;
    }
};