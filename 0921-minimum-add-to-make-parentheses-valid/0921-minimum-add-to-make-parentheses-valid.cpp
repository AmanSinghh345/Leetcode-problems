class Solution {
public:
    int minAddToMakeValid(string s){
        int ans=0;
        int curr=0;
        for(char c : s){
            if(c=='(') curr++;
            else {
                if(curr>0) curr--;
                else ans++;
            }
        }
        ans+=curr;
        return ans;
    }
};