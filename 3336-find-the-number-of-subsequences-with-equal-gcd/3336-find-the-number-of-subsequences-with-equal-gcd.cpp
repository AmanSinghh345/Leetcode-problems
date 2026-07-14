class Solution {
public:
    int mod=1e9+7;
    long long  dp[205][205][205];
    int generateSubsequence(int i,int seq1,int seq2,vector<int>& nums){
        //base case
        if(i==nums.size()){
           if(seq1==seq2){
                return 1;       
           }
           return 0;
        }
        if(dp[i][seq1][seq2]!=-1) return dp[i][seq1][seq2];
        int np=(generateSubsequence(i+1,seq1,seq2,nums))%mod;
        int p=((generateSubsequence(i+1,(int)gcd(seq1,nums[i]),seq2,nums))%mod+(generateSubsequence(i+1,seq1,(int)gcd(seq2,nums[i]),nums))%mod)%mod;
        return dp[i][seq1][seq2]=((np)%mod+p)%mod;
        
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       int seq1=0,seq2=0; 
       int total=0;
        total=(total+(generateSubsequence(0,seq1,seq2,nums))%mod)%mod;
       return total-1;
    }
};