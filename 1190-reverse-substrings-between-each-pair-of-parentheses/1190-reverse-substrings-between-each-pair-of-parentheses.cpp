class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for(char c : s){
            if(c=='(') st.push(res.size());
            else if(c==')'){
                int len=st.top();
                st.pop();
                reverse(res.begin()+len,res.end());
            }
            else res+=c;
        }
        return res;
    }
};