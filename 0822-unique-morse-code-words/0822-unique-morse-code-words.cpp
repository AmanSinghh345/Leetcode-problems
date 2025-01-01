class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        map<char,string> mp;
        char c='a';
        for(int i=0;i<morse.size();i++){
            mp[c]=morse[i];
            c+=1;
        }
        int n=words.size();
        set<string> st;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<words[i].size();j++){
                s+=mp[words[i][j]];
            }
            st.insert(s);
        }
        return st.size();
    }
};