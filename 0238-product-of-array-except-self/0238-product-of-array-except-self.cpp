class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cntZero=0;
        int nonZeroProduct=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) cntZero++;
            else nonZeroProduct*=nums[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(cntZero>0) ans[i]=0;
                else ans[i]=(nonZeroProduct/nums[i]);
            }
            else {
                if(cntZero>1) ans[i]=0;
                else ans[i]=nonZeroProduct;
            }
        }
        return ans;
    }
};