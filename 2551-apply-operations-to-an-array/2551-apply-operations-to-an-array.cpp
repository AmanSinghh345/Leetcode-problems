class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(n>1){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
            n--;
            i++;
        }
        int cnt=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt++;
            else{
                ans.push_back(nums[i]);
            }
        }
        while(cnt--) ans.push_back(0);
        return ans;



       
    }
};