class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
       
        vector<int> mergedArray;
        for(int i = 0; i < n1; i++){
            mergedArray.push_back(nums1[i]);
        }
        for(int i = 0; i < n2; i++){
            mergedArray.push_back(nums2[i]);
        }
        
        sort(mergedArray.begin(), mergedArray.end());
        int n = mergedArray.size();
        
        if (n % 2 == 0) {
            double median = (mergedArray[(n / 2) - 1] + mergedArray[n / 2]) / 2.0;
            return median;
        } else {
            return mergedArray[n / 2];
        }
    }
};
