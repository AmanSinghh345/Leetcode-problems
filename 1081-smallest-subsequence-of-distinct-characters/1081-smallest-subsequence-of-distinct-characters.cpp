class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        vector<int> vis(26,0);
        for(int c:s) freq[c-'a']++;
        stack<char> st;
        for(int c:s){
            freq[c-'a']--;
            if(vis[c-'a']) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0){
                vis[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            vis[c-'a']=true;
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