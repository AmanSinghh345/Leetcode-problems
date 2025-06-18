class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int l=0,r=0;
        int n=nums.size();
        int cnt=0;
        while(r<n){
 if(nums[r]==1){
                cnt++;
                r++;
            }
            else {
                l=r+1;
                r=r+1;
                cnt=0;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};