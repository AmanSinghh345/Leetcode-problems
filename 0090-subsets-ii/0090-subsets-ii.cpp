class Solution {
public:
  void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
    if(index>=nums.size()){
    
        ans.push_back(output);
        return;
    }
    //ex
    solve(nums,output,index+1,ans);
    //in
    int ele=nums[index];
    output.push_back(ele);
    solve(nums,output,index+1,ans);
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        sort(nums.begin(),nums.end());
        solve(nums,output,index,ans);

        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;        
    }
};