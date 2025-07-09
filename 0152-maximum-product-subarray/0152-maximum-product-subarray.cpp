class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi;
        for(int i=0;i<n;i++){
                int curr=nums[i];
                maxi=max(maxi,curr);
                
            for(int j=i+1;j<n;j++){
                curr*=nums[j];
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};