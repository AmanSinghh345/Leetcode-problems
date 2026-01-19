class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int> & nums,int k)
    {
        int cnt=0;
        int n=nums.size();
        int l=0;
        int oddcnt=0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]&1) oddcnt++;
            while(l<n and oddcnt>k)
            {
                if(nums[l]&1) oddcnt--;
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};