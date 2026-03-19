class Solution {
public:
    bool check(int mid,vector<int>& a,int k){
        int cnt=0;
        int sum=0;
        for(int i=0;i<a.size();i++){
            if(sum+a[i]>mid){
                cnt++;
                sum=a[i];
            }
            else sum+=a[i];
        }
    
    cnt++; //last 
    if(cnt>k) return false;
    return true; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
       
        int l=*max_element(weights.begin(),weights.end()),r=accumulate(weights.begin(),weights.end(),0);
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,weights,days)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};