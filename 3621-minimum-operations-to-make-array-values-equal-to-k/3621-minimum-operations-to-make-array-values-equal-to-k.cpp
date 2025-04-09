class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
         int mini=*min_element(nums.begin(),nums.end());
        if(mini==k && maxi==k) return 0;
        if(maxi<=k || mini<k) return -1;
        int cnt=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==k) continue;
            if(nums[i]!=nums[i+1] ) cnt++;
        }
        return cnt;
    }
};