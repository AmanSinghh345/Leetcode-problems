class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int mon=0;
        int prev=mon;
        while(n>0)
        {
            int val=mon+1;
            int cnt=0;
            while(cnt<7 and n>0)
            {
                ans+=val;
                val++;
                n--;
                cnt++;
            }
            prev=mon;
            mon=prev+1;
        }
        return ans;
    }
    
};