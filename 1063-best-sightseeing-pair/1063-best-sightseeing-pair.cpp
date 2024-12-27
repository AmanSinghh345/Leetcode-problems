class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = INT_MIN;
        int best_i = values[0] + 0; 

        for (int j = 1; j < values.size(); j++) {
            // Calculate max score for pair (i, j)
            maxScore = max(maxScore, best_i + values[j] - j);
            best_i = max(best_i, values[j] + j);
        }

        return maxScore;
    }
};
