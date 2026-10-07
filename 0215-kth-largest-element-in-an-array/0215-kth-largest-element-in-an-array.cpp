class Solution {
public:
  
    int quickSelect(int l,int r,int target,vector<int>& nums){
        while(l<=r){
            int randomIdx=l+rand()%(r-l+1);
            int pivot=nums[randomIdx];
            int lt=l;
            int mid=l;
            int gt=r;
            while(mid<=gt){
                if(nums[mid]<pivot){
                    swap(nums[lt],nums[mid]);
                    lt++;
                    mid++;
                }
                else if(nums[mid]==pivot){
                    mid++;
                }
                else{
                    swap(nums[mid],nums[gt]);
                    gt--;
                }
            }
           
            if(lt>target) r=lt-1;
            else  if(gt<target) l=gt+1;
            else return nums[target];

        }
        return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickSelect(0,n-1,n-k,nums);
    }
};