class Solution {
public:
    
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<int> sieve(n+1,1);
        for(int i=2;i<=n;i++){
            if(sieve[i]==1){
                for(long long j=(long long)i*i;j<=n;j+=i){
                    sieve[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(sieve[i]==1) cnt++;
        }
        return cnt;
    }
};