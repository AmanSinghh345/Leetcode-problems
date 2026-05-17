class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);

        int l=0,r=m;
        while(l<=r){
            int mid=l+(r-l)/2;

            int cut1=mid;
            int cut2=(n+m+1)/2-cut1;

            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int r1=(cut1==m)?INT_MAX:nums1[cut1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r2=(cut2==n)?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0) {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2) r=cut1-1;
            else l=cut1+1;

        }
        return 0;
    }
};