class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
            int n=nums.size();
            int subsets=1<<n;
            vector<vector<int>> ans;
            for(int row=0;row<=subsets-1;row++){
                vector<int> curr;
                for(int col=0;col<n;col++){
                    if(row&(1<<col))
                        curr.push_back(nums[col]);
                }
                ans.push_back(curr);
            }
            return ans;
    }
};