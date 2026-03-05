class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        for(int i=0;i<n-1;i++)
        {   

            int first =nums[i];
            int second = target - first;
            for(int j=i+1;j<n;j++)
            {
                if(second==nums[j])
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};