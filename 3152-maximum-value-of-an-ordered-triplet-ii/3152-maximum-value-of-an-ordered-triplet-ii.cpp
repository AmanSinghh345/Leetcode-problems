class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        // Prefix max array
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        // Suffix max array
        vector<int> suff(n);
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], nums[i]);
        }

        long long ans = 0;

        // Iterate from index 1 to n-2 for valid triplets
        for (int i = 1; i < n - 1; i++) {
            long long val = (long long)(pre[i - 1] - nums[i]) * suff[i + 1];
            ans = max(ans, val);
        }

        return ans;
    }
};
