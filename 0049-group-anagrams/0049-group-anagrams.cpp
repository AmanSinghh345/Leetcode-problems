class Solution {
public:
    int mod=1e9+7;
    vector<int> generatePrimes(int n){
        int limit=10000;
        vector<bool> isPrime(limit,true);
        vector<int> res;
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<limit && res.size()<n ;i++){
            if(isPrime[i]){
                res.push_back(i);
                for(int j=1LL*i*i;j<limit;j+=i) isPrime[j]=false;
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes=generatePrimes(26);
        
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