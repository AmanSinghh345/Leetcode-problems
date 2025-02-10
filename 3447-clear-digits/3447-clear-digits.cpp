class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int n=s.size();
         char c;
        for(int i=0;i<n;i++){
            if(s[i]-'0'>9){
                c=s[i];
                ans.push_back(c);
            }
            if(s[i]-'0'<=9){
                ans.pop_back();
            }
        }
        return ans;
    }
};