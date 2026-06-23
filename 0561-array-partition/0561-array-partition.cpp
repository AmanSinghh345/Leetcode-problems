class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};