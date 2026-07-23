class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pivot=1;
        int lt=0;
        int n=nums.size();
        int mid=0;
        int gt=n-1;
        while(mid<=gt){
            if(nums[mid]<pivot){
                swap(nums[lt],nums[mid]);
                lt++;
                mid++;
            }
            else if(nums[mid]>pivot){
                swap(nums[mid],nums[gt]);
                gt--;
            }
            else mid++;
        }
    }
};