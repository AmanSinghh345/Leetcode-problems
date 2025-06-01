class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long  ans=0;
        int start=max(0,n- 2*limit);
        int end=min(n,limit);
        for(int i=start;i<=end;i++){
           int sstart=max(0,n-i-limit);
           int send=min(n-i,limit);
           if(sstart<=send){
            long long  cnt=(send-sstart+1);
            ans+=cnt;
           }
        }
        return ans;
    }
};