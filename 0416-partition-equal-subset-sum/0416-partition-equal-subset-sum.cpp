class Solution{
    public :bool solveTebu(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(target + 1, vector<bool>(n + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[0][i] = true;
        }

        for (int t = 1; t <= target; t++) {
            for (int i = n - 1; i >= 0; i--) {
                bool exc = dp[t][i + 1];
                bool inc = (t >= nums[i]) ? dp[t - nums[i]][i + 1] : false;

                dp[t][i] = inc || exc;
            }
        }

        return dp[target][0];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // Recursive approach (brute force)
        // return solve(nums, target, 0);

        // Memoization approach
        // vector<vector<int>> dp(target + 1, vector<int>(n, -1));
        // return solveMemo(nums, target, 0, dp);

        // Tabulation approach (preferred)
        return solveTebu(nums, target);
    }
};