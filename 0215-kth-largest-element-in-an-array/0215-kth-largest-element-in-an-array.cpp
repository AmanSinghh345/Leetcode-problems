#define all(x) x.begin(),x.end()
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(all(nums));
        int n=nums.size();
        return nums[n-k];
    }
};