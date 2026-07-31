class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(string& s : strs){
            vector<int> freq(26,0);
            for(char & c:s) freq[c-'a']++;

            string key="";
            for(int & x:freq) key=key+"#"+to_string(x);
            umap[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [key,group]:umap) ans.push_back(group);
        return ans;
    }
};