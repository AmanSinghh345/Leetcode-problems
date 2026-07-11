class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> ans;
        for(int i=0;i<n;i++){
            while(nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1]){ ans.insert(nums[i]);break;}
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        vector<int> temp(ans.begin(),ans.end());
        return temp;
    }
};