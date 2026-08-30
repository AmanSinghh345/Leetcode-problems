class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int maxInd,minInd;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                maxInd=i;
            }
            if(nums[i]==mini){
                minInd=i;
            }
        }
        if(maxInd>minInd) swap(maxInd,minInd);
        if(maxInd==minInd) return 1;
        return min({minInd+1,maxInd+1+n-minInd,n-maxInd});
    }

};