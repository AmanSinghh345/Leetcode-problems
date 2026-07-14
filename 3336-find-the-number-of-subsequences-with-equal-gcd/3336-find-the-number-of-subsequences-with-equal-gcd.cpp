class Solution {
public:
    
    int subsequencePairCount(vector<int>& nums) {
        int dp[2][205][205];
        memset(dp,-0,sizeof(dp));
        int n=nums.size();
        int total=0;
        int mod=1e9+7;
        //base case 
        for(int seq=0;seq<205;seq++){
            dp[n%2][seq][seq]=1;
        }

        for(int i=n-1;i>=0;i--){
             int curr=i%2;
             int next=(i+1)%2;
            int next_gcd[205];
            for(int s=0;s<205;s++){
                next_gcd[s]=gcd(s,nums[i]);
            }
             for(int seq1=0;seq1<205;seq1++){
                for(int seq2=0;seq2<205;seq2++){
                    long long  ways=dp[next][seq1][seq2];

                  
                    ways+=dp[next][next_gcd[seq1]][seq2];
                    
                    ways+=dp[next][seq1][next_gcd[seq2]];
                    
                    dp[curr][seq1][seq2]=ways%mod;
                }
             }
        }
       
       return (dp[0][0][0]-1+mod)%mod;
    }
};