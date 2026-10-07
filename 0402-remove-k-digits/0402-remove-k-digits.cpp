class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string s;
        for(char c : num){
            while(s.size()>0 && s.back()>c && k>0) {
                s.pop_back();
                k--;
            }
            s.push_back(c);
        }
        while(k>0){
            s.pop_back();
            k--;
        }
        int i=0;
        for(;i<s.size();i++){
            if(s[i]!='0') break;
        }
        string ans=s.substr(i);
        if(ans.empty()) return "0";
        return ans;
    }
};