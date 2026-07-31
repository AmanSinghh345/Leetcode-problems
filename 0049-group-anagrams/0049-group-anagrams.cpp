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
        vector<vector<string>> ans(n);
        int i=0;
        for(auto & it : umap){
            for(string & s:it.second){
                 ans[i].push_back(s);
            }
            i++;
        }
        return ans;
    }
};