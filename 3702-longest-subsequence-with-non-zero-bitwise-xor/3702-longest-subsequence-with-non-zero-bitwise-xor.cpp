class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        int cnt=0;
        for(int x:nums) {
            xorr^=x;
            if(x!=0) cnt++;
        }
        
        if(xorr!=0) return n;
        if(cnt>1) return n-1;
        return 0;
    }
};