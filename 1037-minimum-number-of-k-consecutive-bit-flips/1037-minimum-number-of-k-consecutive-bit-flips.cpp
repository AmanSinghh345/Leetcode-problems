class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0;
        int curr=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>=k)
            {
               if( nums[i-k]==2)  curr--;
            }
            if(curr%2==nums[i])
            {
                if(i+k>n) return -1;
                nums[i]=2;
                curr++;
                ans++;
            }
        }
        return ans;
    }
};