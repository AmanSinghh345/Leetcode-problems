class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        
        function<long long(int)> dfs = [&](int i) {
            if (i >= n) return 0LL; // Base case
            if (dp[i] != -1) return dp[i]; // Return if already computed
            
            // Solve the current question
            long long solve = questions[i][0] + dfs(i + questions[i][1] + 1);
            // Skip the current question
            long long skip = dfs(i + 1);
            
            return dp[i] = max(solve, skip);
        };

        return dfs(0);
    }
};