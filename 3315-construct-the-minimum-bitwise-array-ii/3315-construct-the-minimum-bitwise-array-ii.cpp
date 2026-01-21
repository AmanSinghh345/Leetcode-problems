class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
            } else {
                int k = __builtin_ctz(~nums[i]);
                ans[i] = nums[i] - (1 << (k - 1));
            }
        }
        return ans;
    }
};
