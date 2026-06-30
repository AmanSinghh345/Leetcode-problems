class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0,cnt=0;
        for(int x:nums){
            if(x==0) cnt=0;
            else cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};