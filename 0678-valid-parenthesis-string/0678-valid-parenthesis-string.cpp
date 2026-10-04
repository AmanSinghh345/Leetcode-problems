class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1;
        stack<int> s2;
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('){
                s1.push(i);
            }
            else if(c=='*'){
                s2.push(i);
            }
            else{
                if(s1.empty() and s2.empty()) return false;
                else if(!s1.empty()){
                    s1.pop();
                }
                else if(s1.empty() and !s2.empty()){
                    s2.pop();
                }
            }
        }
        while(!s1.empty() and !s2.empty() and s1.top()<s2.top()){
            s1.pop();
            s2.pop();
        }
        if(s1.empty()) return true;
        return false;
    }
};