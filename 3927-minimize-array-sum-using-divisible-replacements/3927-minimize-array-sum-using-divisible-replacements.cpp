const int MAXN=1e5+7;
int cnt[MAXN];
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n=nums.size();

        for(auto it : nums)  cnt[it]++;
        
        long long ans=0;
       for(int i=1;i<MAXN;i++){

            if(cnt[i]){

                for(int j=2*i;j<MAXN;j+=i){
                    cnt[i]+=cnt[j];
                    cnt[j]=0;
                }
                ans+=(cnt[i]*(long long ) i);
            }
       }
       fill_n(cnt,MAXN,0);
       return ans;
    }
};