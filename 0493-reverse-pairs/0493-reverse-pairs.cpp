class Solution {
public:
    int CountPairs(vector<int>& nums,int l,int mid,int r){
        int cnt=0;
        int right=mid+1;
        for(int left=l;left<=mid;left++){
            while(right<=r and (nums[left]/2.0)>nums[right]) right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
    void merge(vector<int>& nums,int l,int mid,int r){
        vector<int> temp;
        int left=l;
        int right=mid+1;
        while(left<=mid and right<=r){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=r) temp.push_back(nums[right++]);
        for(int i=l;i<=r;i++) nums[i]=temp[i-l];
    }
    int mergeSort(vector<int>& nums ,int l,int r){
        if(l>=r) return 0;
        int mid=(l+r)/2;
        int a=mergeSort(nums,l,mid);
        int b=mergeSort(nums,mid+1,r);
        int c=CountPairs(nums,l,mid,r);

        merge(nums,l,mid,r);
        return a+b+c;
    }
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);
    }
};