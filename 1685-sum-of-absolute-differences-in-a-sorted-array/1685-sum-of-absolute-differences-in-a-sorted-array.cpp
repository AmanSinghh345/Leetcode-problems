class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        int pref=0;
        for(int i=1;i<=n;i++){
            pref+=nums[i-1];
            prefix[i]=pref;
        }

        vector<int> ans(n);
        for(int i=1;i<=n;i++){
            int rightAdd=prefix[n]-prefix[i];
            int rightSub=nums[i-1]*(n-i);
            int leftSub=prefix[i-1];
            int leftAdd=(i-1)*nums[i-1];
            ans[i-1]=(leftAdd-leftSub)+(rightAdd-rightSub);
        }
        return ans;
      
    }
};