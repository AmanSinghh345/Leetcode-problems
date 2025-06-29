class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr=start^goal;
        int cnt=__builtin_popcount(xorr);
        return cnt;
    }
};
