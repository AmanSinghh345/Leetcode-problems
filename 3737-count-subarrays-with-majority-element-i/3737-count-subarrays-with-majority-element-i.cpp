class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        long long cnt=0;
        vector<long long > freq(n,0);
        long long  pref=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target) pref++;
            freq[i]=pref;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
              long long cntTarget=freq[j];
              if(i>0) cntTarget-=freq[i-1];
               if(cntTarget*2>(j-i+1)) cnt++;
            }
        }
        return cnt;
    }
};