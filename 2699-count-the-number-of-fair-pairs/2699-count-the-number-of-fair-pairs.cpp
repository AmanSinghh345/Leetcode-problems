class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt=0;
        sort(nums.begin(),nums.end());
        deque<int> temp;
        for(auto el : nums){
            temp.push_back(el);
            
        }
        for(int i=0;i<nums.size();i++){
            temp.pop_front();
            auto low=lower_bound(temp.begin(),temp.end(),lower-nums[i]);
            auto high=upper_bound(temp.begin(),temp.end(),upper-nums[i]);
            cnt+=(high-low);
        }
        return cnt;
    }
};