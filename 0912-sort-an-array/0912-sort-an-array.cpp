class Solution {
public:
    void merge(int l,int mid,int r,vector<int>& nums){
        int n1=mid-l+1;
        int n2=r-mid;

        vector<int> left(n1),right(n2);
        for(int i=0;i<n1;i++) left[i]=nums[l+i];
        for(int j=0;j<n2;j++) right[j]=nums[mid+1+j];
        int k=l;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(left[i]<right[j]){
                nums[k]=left[i];
                i++;
                k++;
            }
            else {
                nums[k]=right[j];
                j++;
                k++;
            }
        }
        while(i<n1){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=right[j];
            j++;
            k++;
        }
        
    }
    void mergeSort(int l,int r,vector<int>& nums){
        if(l>=r) return ;
        int mid=l+(r-l)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        merge(l,mid,r,nums);
        return ;
    }
    vector<int> sortArray(vector<int>& nums) {
       int n=nums.size();
       mergeSort(0,n-1,nums);
       return nums;    
    }
};