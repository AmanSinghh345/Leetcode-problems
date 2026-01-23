class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        int a,b;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]==2)
            {
                b=nums[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(freq[i]==0)
            {
                a=i;
            }
        }
        return {b,a};
    }
};