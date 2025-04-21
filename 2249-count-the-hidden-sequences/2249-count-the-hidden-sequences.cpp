class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long cur = 0, maxi = 0, mini = 0;
        for (auto& d : differences) {
            cur += d;
            maxi = max(maxi, cur);
            mini = min(mini, cur);
        }
        long long spread = maxi - mini;
        if (lower + spread > upper) return 0;
        return upper - (lower + spread) + 1;
    }
};