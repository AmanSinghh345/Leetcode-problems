class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int range=maxi-mini+1;
        vector<int> cntArr(range,0);
        int n=nums.size();
        for(int i=0;i<n;i++) cntArr[nums[i]-mini]++;

        vector<int> ans;
        for(int i=0;i<range;i++){
            while(cntArr[i]--){
                ans.push_back(i+mini);
            }
        }
        return ans;
    }
};