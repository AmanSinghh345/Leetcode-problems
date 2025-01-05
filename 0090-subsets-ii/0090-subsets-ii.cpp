class Solution {
public:
    void func(int ind,vector<int>& temp,vector<int>& nums,vector<vector<int>>& ans){
            ans.push_back(temp);
      for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        func(i+1,temp,nums,ans);
        temp.pop_back();

      }
      return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     vector<vector<int>> ans;
     vector<int> temp;
     int ind=0;
     func(ind,temp,nums,ans);
     return ans;
    }
};