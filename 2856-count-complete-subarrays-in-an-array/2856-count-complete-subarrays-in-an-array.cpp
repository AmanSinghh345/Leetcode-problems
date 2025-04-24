class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        // Count distinct elements in the original array
        unordered_set<int> distinct;
        for (int num : nums) {
            distinct.insert(num);
        }
        int totalDistinct = distinct.size();
        
        int count = 0;
        
        // For each starting point
        for (int start = 0; start < n; start++) {
            unordered_set<int> currentDistinct;
            
            // Extend the subarray
            for (int end = start; end < n; end++) {
                currentDistinct.insert(nums[end]);
                
                // If current subarray has all distinct elements
                if (currentDistinct.size() == totalDistinct) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
