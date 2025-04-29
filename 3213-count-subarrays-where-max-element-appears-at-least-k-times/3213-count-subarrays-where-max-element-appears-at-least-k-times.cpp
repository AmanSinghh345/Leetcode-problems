class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            mx = max(nums[i], mx);
        }
        int last = 0, freq = 0;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq += (nums[i] == mx);
            while (last < i && freq - (nums[last] == mx) >= k) {
                freq -= (nums[last] == mx);
                last++;
            }
            if (freq >= k) {
                res += (last + 1);
            }
        }
        return res;
    }
};