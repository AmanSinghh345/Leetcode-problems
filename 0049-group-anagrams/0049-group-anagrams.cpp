class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;

        for(const auto & s : strs){
            vector<int> freq(26,0);
            for(const char &c:s){
                freq[c-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+="#"+to_string(freq[i]);
            }

            umap[key].push_back(s);
        }
        for(const auto &[a,b]:umap){
            ans.push_back(b);
        }
        return ans;
    }
};