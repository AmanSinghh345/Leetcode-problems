class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        bitset<26> used;
        for(int c:s) freq[c-'a']++;
        stack<char> st;
        for(int c:s){
            freq[c-'a']--;
            if(used.test(c-'a')) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0) {
                used.reset(st.top()-'a');
                st.pop();
            }
            used.set(c-'a');
            st.push(c);
        }

        string ans="";
        while(!st.empty()){
            char c=st.top();
            st.pop();
            ans=c+ans;
        }
        return ans;
    }
};