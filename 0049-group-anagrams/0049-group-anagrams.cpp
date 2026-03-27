class Solution {
public:
    int mod=1e9+7;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes={
            2,3,5,7,11,13,17,19,23,29,
            31,37,41,43,47,53,59,61,
            67,71,73,79,83,87,89,97,101
        };
        
        unordered_map<long long, vector<string>> umap;
        vector<vector<string>> ans ;
        int n=strs.size();
        for(const auto &s:strs){
            
            long long key=1;
            for(const auto& c : s){
                key=(key*1LL*primes[c-'a'])%mod;
            }
            umap[key].push_back(s);
        }
        for(const auto &[a,b]:umap){
            ans.push_back(b);
        }
        return ans;
    }
};