class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> u;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int req=target-nums[i];
            if(u.count(req)) return {u[req],i};
            u[nums[i]]=i;
        }
        return {};
    }
};