class Solution {
public:
    void find(int ind,vector<int>& nums,set<vector<int>>& st){
        if(ind==nums.size()) {
            st.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            find(ind+1,nums,st);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        find(0,nums,st);
        vector<vector<int>> ans;
        for(auto& it : st) ans.push_back(it);
        return ans;
    }
};