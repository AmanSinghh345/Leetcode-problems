class Solution {
public:
    void recurr(vector<vector<int>>& ans, vector<int>& nums, vector<int>& output, int i) {
        if(i == nums.size()) {
            ans.push_back(output);
            return;
        }
        // include
        output.push_back(nums[i]);
        recurr(ans, nums, output, i + 1);
        output.pop_back();

        // exclude
        recurr(ans, nums, output, i + 1);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        recurr(ans, nums, output, 0);

        int sum = 0;
        for(auto& subset : ans) {
            int xorr = 0;
            for(int num : subset) {
                xorr ^= num;
            }
            sum += xorr;
        }
        return sum;
    }
};
