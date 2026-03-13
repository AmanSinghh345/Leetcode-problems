class Solution {
public:
typedef long long ll;
ll bs(ll mid,ll val){
     ll z=mid/val;
     z;
     ll start=1;
     ll end=z;
     ll v=end;
     while(start<=end){
        ll m=start+(end-start)/2;
        if((__int128)m*(m+1)/2<=z){
            v=m;
            start=m+1;
        }
        else{
            end=m-1;
        }
     }
     return v;
}
bool check(int mountainHeight, vector<int>& workerTimes,ll mid){
    ll total=0;
    int n=workerTimes.size();
    for(int i=0;i<n;i++){
       ll count=bs(mid,workerTimes[i]);
       total+=count;
    }
    if(total>=mountainHeight)return true;
    return false;
}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=0 ,r=LLONG_MAX;
        long long ans=r;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(check(mountainHeight,workerTimes,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};