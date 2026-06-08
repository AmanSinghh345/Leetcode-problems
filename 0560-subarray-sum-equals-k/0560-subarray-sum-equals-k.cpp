class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int cnt=0;
        map<int,int> mp;
        mp[0]=1;
        for(int x: nums){
            sum+=x;
            int remove=sum-k;
            if(mp.count(remove)) cnt+=mp[remove];
            mp[sum]++;
        }
        return cnt;
    }
};