class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        int i=0,j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                a.push_back(nums1[i]);
                i++;
            }
            else{
                a.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            a.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            a.push_back(nums2[j]);
            j++;
        }

        if((n1+n2)&1){
            return (double)a[(n1+n2)/2];
        }
        return (double)((a[(n1+n2)/2 - 1])+ a[(n1+n2)/2])/2.0;
    }
};