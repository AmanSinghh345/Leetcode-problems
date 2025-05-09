class Solution {
public:
    int mySqrt(int x) {
        //Binary Search 
        long long  low=0;
        long long high=1e9;
        long long  ans=1e9;
        while(low<=high){
            long long  mid=(low+high)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid<x) {
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
};