class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(26,0),freq2(26,0);
        for(char& c:s) freq1[c-'a']++;
        for(char& c:t) freq2[c-'a']++;
        string key1="",key2="";
        for(int i=0;i<26;i++){
            key1=key1+"#"+to_string(freq1[i]);
            key2=key2+"#"+to_string(freq2[i]);
        }
        return key1==key2;
    }
};