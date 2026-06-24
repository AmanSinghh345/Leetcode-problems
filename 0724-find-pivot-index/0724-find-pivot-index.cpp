class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+nums[i];
        int total=pref[n];
        for(int i=1;i<=n;i++){
            if(pref[i-1]==(total-pref[i])) return i-1;
        }
        return -1;

    }
};