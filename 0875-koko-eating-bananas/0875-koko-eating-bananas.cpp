class Solution {
public:
    bool check(int mid,vector<int>& a,int h){
        long long H=1LL*h;
        long long cnt=0;
        // int lb=upper_bound(a.begin(),a.end(),mid)-a.begin();
        // cnt+=(lb+1);
        for(int i=0;i<a.size();i++){
           cnt+=(a[i]+mid-1)/mid;
        }
        if(cnt>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int l=1,r=piles[n-1];
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;

            if(check(mid,piles,h)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};