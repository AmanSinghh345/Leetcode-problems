class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        if(n==1) return nums[0];
        for(int i=1;i<n-1;i++)
        {
            int take=nums[i];
            if(i>1)
            {
                take+=prev2;
            }
            int not_take=0 + prev;
            int curi=max(take,not_take);
            prev2=prev;
            prev=curi;
        }
        int val1=prev;
        prev2=0;
        prev=nums[1];
        for(int i=2;i<n;i++)
        {
            int take=nums[i];
            if(i>2){
                take+=prev2;
            }
            int not_take=0 + prev;
            int curi=max(take,not_take);
            prev2=prev;
            prev=curi;
        }
        int val2=prev;
        return max(val2,val1);
    }
};