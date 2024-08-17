class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> ans(n, 0); // Use long long to avoid overflow
        long long result = 0;

        for (int i = 0; i < m; i++) {
            // Create a new vector for the current row's maximum points
            vector<long long> curr(n, 0);
            
            // Add the current row points to the current answer
            for (int j = 0; j < n; j++) {
                curr[j] = ans[j] + points[i][j];
            }

            // Left to right pass for maximizing points
            for (int j = 1; j < n; j++) {
                curr[j] = max(curr[j], curr[j-1] - 1);
            }

            // Right to left pass for maximizing points
            for (int j = n - 2; j >= 0; j--) {
                curr[j] = max(curr[j], curr[j+1] - 1);
            }

            // Update ans to be the current row's maximum points
            ans = curr;
        }

        // Find the maximum result after processing all rows
        for (int i = 0; i < n; i++) {
            result = max(result, ans[i]);
        }

        return result;
    }
};
