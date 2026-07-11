class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int diff=0;
        for(int x:nums){
            diff+=(x-mini);
        }
        return diff;
    }
};