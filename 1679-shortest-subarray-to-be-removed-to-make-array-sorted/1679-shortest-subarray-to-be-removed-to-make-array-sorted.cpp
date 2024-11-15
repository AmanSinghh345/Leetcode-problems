class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        
        // Find the left-most sorted part
        while (i + 1 < n && arr[i] <= arr[i + 1])  {
            i++;
        }
        
        if (i == n - 1) return 0;  // The whole array is already sorted
        
        int j = n - 1;
        
        // Find the right-most sorted part
        while (j - 1 >= 0 && arr[j] >= arr[j - 1]) {
            j--;
        }
        
        int cnt = min(n - i - 1, j);  // Initial minimum removal length
        
        int left = 0;
        int right = j;
        
        // Try to merge the two sorted parts
        while (left <= i && right < n) {
            if (arr[left] <= arr[right]) {
                cnt = min(cnt, right - left - 1);
                left++;
            } else {
                right++;
            }
        }
        
        return cnt;
    }
};
