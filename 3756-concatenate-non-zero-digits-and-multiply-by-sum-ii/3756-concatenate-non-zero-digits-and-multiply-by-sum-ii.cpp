class Solution {
public:
    int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<long long > pow10(2*n+1);
        pow10[0]=1;
        for(int i=1;i<=n;i++) pow10[i]=(pow10[i-1]*10)%mod;
        vector<long long > prefix(n+1,0);
        vector<long long > stringPrefix(n+1,0);
        vector<long long > nonZeroCnt(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+(s[i-1]-'0');
            nonZeroCnt[i]=nonZeroCnt[i-1];
            if(s[i-1]!='0') {
                nonZeroCnt[i]++;
                stringPrefix[i]=((stringPrefix[i-1]*10)+(s[i-1]-'0'))%mod;
            }
            else stringPrefix[i]=stringPrefix[i-1];
        }
     
        cout<<endl;
        vector<int> ans;
        int m=queries.size();
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            
            long long  sum=prefix[r+1]-prefix[l];

            long long  cnt=nonZeroCnt[r+1]-nonZeroCnt[l];
            long long  val1=((stringPrefix[l])*pow10[cnt])%mod;
            long long  val2=stringPrefix[r+1];
            long long  num=(val2-val1+mod)%mod;

            int val=(1LL*num*sum)%mod;
            ans.push_back(val);
        }
        return ans;
    }
};