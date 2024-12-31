class Solution {
public:
    int function(vector<int>& days, vector<int>& costs, int n, int idx, vector<int>& dp) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        // Choose the 1-day pass
        int first = costs[0] + function(days, costs, n, idx + 1, dp);
        
        // Choose the 7-day pass
        int i;
        for(i = idx; i < n && days[i] < days[idx] + 7; i++);
        int second = costs[1] + function(days, costs, n, i, dp);
        
        // Choose the 30-day pass
        int j;
        for(j = idx; j < n && days[j] < days[idx] + 30; j++);
        int third = costs[2] + function(days, costs, n, j, dp);
        
        // Take the minimum of all three options
        dp[idx] = min(first, min(second, third));
        return dp[idx];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1); // Change to n instead of n+1
        return function(days, costs, n, 0, dp);
    }
};
