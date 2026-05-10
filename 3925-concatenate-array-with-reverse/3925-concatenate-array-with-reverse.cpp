class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> temp=nums;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++) temp.push_back(nums[i]);
        return temp; 
    }
};