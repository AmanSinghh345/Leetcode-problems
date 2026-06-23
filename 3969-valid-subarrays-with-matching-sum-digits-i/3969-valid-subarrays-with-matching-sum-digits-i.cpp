class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        char target=x+'0';
        vector<long long> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long  sum=pref[j];
                if(i>0) sum-=pref[i-1];
                if(sum%10!=x) continue;
                string s=to_string(sum);
                int sz=s.size();
                if(s[0]==target && s[sz-1]==target) cnt++;
            }
        }
        return cnt;
    }
};