class Solution {
public:

    int quickselect(vector<int>& nums,int low,int high,int target){
           while(low<=high){
            int randomInd=low+rand()%(high-low+1);
            int pivot=nums[randomInd];

            int lt=low;
            int mid=low;
            int gt=high;
            while(mid<=gt){
                if(nums[mid]<pivot){
                    swap(nums[mid],nums[lt]);
                    lt++;
                    mid++;
                }
                else if(nums[mid]>pivot){
                    swap(nums[mid],nums[gt]);
                    gt--;
                }
                else mid++;
            }

          

            if(target<lt) high=lt-1;
            else if(target>gt) low=gt+1;
            else return nums[target];

           }
           return -1;

    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();

        // n-k is the postiion we want
       return  quickselect(nums,0,n-1,n-k);
    }
};