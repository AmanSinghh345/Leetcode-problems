class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(string& s:strs){
            string p=s;
            sort(p.begin(),p.end());
            umap[p].push_back(s);
        }
        int n=umap.size();
        vector<vector<string>> ans;
        for(auto & it : umap){
           ans.push_back(it.second);
        }
        return ans;
    }
};