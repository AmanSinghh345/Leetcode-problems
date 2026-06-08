class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        long long cnt=0;
        long long n=nums.size();
        for(int i=0;i<n;i++){
             if(mp.count(nums[i]-i)) cnt+=mp[nums[i]-i];
             mp[nums[i]-i]++;
        }
        long long total=(n*(n-1))/2;
        return total-cnt;
    }
};