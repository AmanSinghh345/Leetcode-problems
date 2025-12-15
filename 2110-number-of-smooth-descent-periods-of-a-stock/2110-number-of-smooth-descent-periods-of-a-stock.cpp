class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int n=prices.size();
    
        long long  cnt=1;
        if(n==1) return 1;
        for(int i=1;i<n;i++)
        {
          
            if(prices[i]==(prices[i-1]-1))
            {
                cnt++;
            
            }
            else{
            ans+=(long long)((1LL*cnt*(cnt+1))/2);
            cnt=(long long)1;
            }
            if(i==n-1)
            {
                 ans+=(long long)((1LL*cnt*(cnt+1))/2);
            }
        }
        return ans;
    }
};