class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=*min_element(nums1.begin(),nums1.end());
        int p=mini%2;
        int odd=0,even=0;
        for(int x: nums1){
            if(x%2==p) continue;
            else {
                if(p==0) return false; 
            }
        }
        return true;
    }
};