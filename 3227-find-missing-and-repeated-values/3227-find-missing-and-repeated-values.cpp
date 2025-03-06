class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int length = n * n;  // Since it's an n x n grid
        
        vector<int> freq(length + 1, 0); // Frequency array
        int duplicate = -1, missing = -1;
        
        // Count frequency of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        
        // Find missing and repeated values
        for (int i = 1; i <= length; i++) {
            if (freq[i] == 0) missing = i;
            if (freq[i] == 2) duplicate = i;
        }
        
        return {duplicate, missing};
    }
};
