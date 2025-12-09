class Solution {
public:
    int mod=1000000007;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> Suff;
        for(int i=2;i<n;i++)
        {
            Suff[nums[i]]++;
        }
        unordered_map<int,int> Pref;
        Pref[nums[0]]++;
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            int val=nums[i];
            auto l=Pref.find(val*2);
            auto r=Suff.find(val*2);
            if(l!=Pref.end() and r!=Suff.end())
            {
                cnt=(cnt+(Pref[val*2]*1LL*Suff[val*2]))%mod;
            }
            Pref[nums[i]]++;
            Suff[nums[i+1]]--;
        }
        return cnt;
    }
};