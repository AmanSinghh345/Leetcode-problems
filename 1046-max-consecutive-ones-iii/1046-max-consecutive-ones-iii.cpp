class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        int l=0,r=0,len=0,zeroes=0;
        while(r<n){
            if(nums[r]==0) zeroes++;
            if(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};