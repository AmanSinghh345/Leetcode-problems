class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
    int atmost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0;
        int cnt = 0;
        int n=nums.size();
        for(int r = 0; r < n; r++){
            freq[nums[r]]++;
            while (l < n and freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

}
;