class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
       
       
        for(int i=0;i<=n-k;i++){
             bool flag=true;
              int maxi=nums[i];
            for(int j=i+1;j<i+k;j++){
                if(nums[j-1]!=nums[j]-1 ) {
                    ans.push_back(-1);
                    flag=false;
                    break;
                }
                else{
                    maxi=max(maxi,nums[j]);
                }
            }
            if(flag) ans.push_back(maxi);
        }
        return ans;
    }
};