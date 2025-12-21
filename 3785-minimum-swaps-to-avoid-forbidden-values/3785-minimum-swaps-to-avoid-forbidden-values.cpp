class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n=nums.size();
        unordered_map<long long,long long> mp1,mp2,mp3;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            mp1[nums[i]]++;
            mp2[forbidden[i]]++;

            if(nums[i]==forbidden[i])
            {
                cnt++;
                mp3[nums[i]]++;
            }
        }
        if(cnt==0) return 0;
        for(auto &[key,val]:mp1) {
            if(mp1[key]+ mp2[key]>nums.size()) return -1;
        }

        long long maxi=0;
        for(auto &[k,v] : mp3) maxi=max(maxi,v);
        
        return max<int>(maxi,(cnt+1)/2);
    }
};