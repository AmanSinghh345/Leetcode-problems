class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int j=1;j<n-1;j++){

            int val=nums[j];
            int ls=0,lb=0,rs=0,rb=0;
            for(int i=0;i<j;i++){
                if(nums[i]<val) ls++;
                if(nums[i]>val) lb++;
            }
            for(int k=j+1;k<n;k++){
                if(nums[k]<val) rs++;
                if(nums[k]>val) rb++;
            }
            ans+=(ls*rb)+(lb*rs);
        }
        return ans;
    }
};