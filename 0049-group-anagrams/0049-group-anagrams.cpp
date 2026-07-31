class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool> isPrime(1000,true);
        isPrime[0]=isPrime[1]=false;
 
        for(int i=2;i*i<1000;i++){
            if(isPrime[i]){
            for(int j=i*i;j<1000;j+=i){
                isPrime[j]=false;
            }
            }
        }
        vector<long long >  arr;
        long long  mod=1e9+7;
        for(int i=2;i<1000;i++){
           
            if(isPrime[i]) arr.push_back(i); 
             if(arr.size()==26) break;
        }
        unordered_map<long long ,vector<string>> umap;
        for(string& s:strs){
            long long key=1;
            for(char & c:s){
                int d=c-'a';
                key=(1LL*key*arr[d])%mod;
            }
            umap[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [key,group]:umap){
            ans.push_back(group);
        }
        return ans;
    }
};