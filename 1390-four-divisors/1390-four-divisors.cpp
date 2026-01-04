class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0) 
                    {
                        int f=j;
                        int s=nums[i]/j;
                        if(f==s)
                        {
                            cnt++;
                            sum+=f;
                        }
                        else 
                        {
                            cnt+=2;
                            sum+=(f+s);
                        }
                    }
                    if(cnt>4) break;
                
            }
            if(cnt==4) ans+=sum;
        }
        return ans;
    }
};