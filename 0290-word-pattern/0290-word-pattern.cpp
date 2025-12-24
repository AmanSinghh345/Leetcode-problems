class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        unordered_map<char,string> umap;
        vector<string> word;
        for(int i=0;i<s.size();i++)
        {
            string w="";
            while(i<s.size() and s[i]!=' ')
            {
                w+=s[i];
                i++;
            }
            if(i==s.size() or s[i]==' ')
            word.push_back(w);
        }
        if(word.size()!=n) return false;
        unordered_map<string,char> mp;
        for(int i=0;i<n;i++)
        {
            if(umap.find(pattern[i])!=umap.end() and umap[pattern[i]]!=word[i])
            {
                return false;
            }
            else {
                umap[pattern[i]]=word[i];
            }
            if(mp.find(word[i])!=mp.end() and mp[word[i]]!=pattern[i])
            {
                return false;
            }
            else{
                mp[word[i]]=pattern[i];
            }
        }
        return true;
    }
};