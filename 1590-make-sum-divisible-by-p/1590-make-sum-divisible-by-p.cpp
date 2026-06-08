class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long  total=0;
        for(int& x : nums) total+=x;
        if(total%p==0) return 0;
        int r=total%p;
        map<int,int> mp;
        mp[0]=-1;
        long long  pref=0;
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            int need=(pref%p-r+p)%p;
            if(mp.count(need))  ans=min(ans,i-mp[need]);
            mp[pref%p]=i;
        }
        if(ans==n) return-1;
        return ans;
    }
};