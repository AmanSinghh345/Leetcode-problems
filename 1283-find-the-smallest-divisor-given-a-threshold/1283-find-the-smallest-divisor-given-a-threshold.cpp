class Solution {
public:
    bool check(int mid,vector<int>& a,int k){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            cnt+=(a[i]+mid-1)/mid;
        }
        if(cnt<=k) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=1,r=nums[n-1];
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};