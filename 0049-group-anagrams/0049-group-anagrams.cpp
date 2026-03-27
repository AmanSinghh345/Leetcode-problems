class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,vector<string>> umap;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            umap[s].push_back(strs[i]);
        }
        for(auto [a,b] : umap){
             ans.push_back(b);
        }
        return ans;
    }
};