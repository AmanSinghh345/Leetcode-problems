class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //no of missing number before ith index is nums[i]-(i+1)
        // 2 3 4 7 11 then 1 1 1 3 6
        // first index where missing >=5  l=4 and k=5 ans=l+k=9

        // 1 2 3 4 then 0 0 0 0  L become 4 and k is 2 so  ans l+k > 4+2 >6

        int l=0,r=arr.size()-1;

        while(l<=r){
            int mid=(l+r)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k) l=mid+1;
            else r=mid-1;  
        }
        return l+k;

    }
};