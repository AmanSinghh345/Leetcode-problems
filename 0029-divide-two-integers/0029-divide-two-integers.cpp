class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend < 0) == (divisor < 0);

        long long n = abs(1LL * dividend);
        long long m = abs(1LL * divisor);
        long long ans = 0;

        while (n >= m) {
            long long cnt = 0;
            while (n >= (m << cnt)) {
                cnt++;
            }
            cnt--;  // Correct the overstep
            ans += 1LL << cnt;
            n -= m << cnt;
        }

        if (!sign) ans = -ans;

        return (int)ans;
    }
};
