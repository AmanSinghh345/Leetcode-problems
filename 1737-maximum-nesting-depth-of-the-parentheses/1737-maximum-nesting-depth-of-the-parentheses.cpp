class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int cnt=0;
        stack<char> st;
        for(char c: s){
            if(c=='(') st.push(c);
            else if(c==')') st.pop();
            cnt=max(cnt,(int)st.size());
        }
        return cnt;
    }
};