class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            int sum=nums[i];
            for(int j=1;j<=nums[i]/2;j++)
            {
                if(nums[i]%j==0) {
                    cnt++;
                    sum+=j;
                    if(cnt>4) break;
                }
            }
            if(cnt==4) ans+=sum;
        }
        return ans;
    }
};