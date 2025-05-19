class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        swap(nums1,nums2);
        int n=nums1.size();
        int m=nums2.size();
        int l=0,r=n;
        double ans=0;
        while(l<=r){
            int cut1=(l+r)/2;
            int cut2=(n+m+1)/2 - cut1;
            int left1=(cut1==0?INT_MIN:nums1[cut1-1]);
            int left2=(cut2==0?INT_MIN:nums2[cut2-1]);
            int right1=(cut1==n?INT_MAX:nums1[cut1]);
            int right2=(cut2==m?INT_MAX:nums2[cut2]);
            if(left1<=right2 and left2<=right1){
                ans=max(left1,left2);
                if((n+m)%2==0) ans=(ans+min(right1,right2))/2;
                break;
            }
            else if(left1>right2) r=cut1-1;
            else l=cut1+1;
        }
        return ans;
    }
};