class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        bool a=false , b=false ,c =false;
        int i=0;
            while(i+1<n and nums[i+1]>nums[i])
            {
                i++;
                a=true;
            }
            while(i+1 < n and nums[i+1]<nums[i])
            {
                i++;
                b=true;
            }
            while(i+1<n and nums[i+1]>nums[i])
            {
                i++;
                c=true;
            }
        if(i<n-1) return 0;
        if( a and b and c ) return 1;
        return 0;
            }
};