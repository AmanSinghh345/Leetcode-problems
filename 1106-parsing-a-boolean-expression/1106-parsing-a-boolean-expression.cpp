class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char c : expression){
            if(c==',') continue;
            else if(c!=')') {
                st.push(c);
            }
            else{
                int nt=0,nf=0;
                while(st.top()=='f' || st.top()=='t'){
                    if(st.top()=='f') nf++;
                    else nt++;
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char res;
                if(op=='!') res=nf?'t' : 'f';
                else if(op=='&') res=nf?'f':'t';
                else res=nt?'t':'f';
                st.push(res);
            }
        }
        if(st.top()=='t') return true;
        return false;
    }
};