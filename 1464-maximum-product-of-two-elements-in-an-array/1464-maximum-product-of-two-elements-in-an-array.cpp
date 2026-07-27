class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=INT_MIN,smx=INT_MIN;
        for(int x:nums){
            if(x>mx){
                smx=mx;
                mx=x;
            }
            else if(x<=mx && x>smx) smx=x;
        }
        return (mx-1)*(smx-1);
    }
};