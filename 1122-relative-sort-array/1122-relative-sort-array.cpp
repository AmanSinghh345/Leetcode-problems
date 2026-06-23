class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int maxi=*max_element(arr1.begin(),arr1.end());
        vector<int> freq(maxi+1,0);
        for(int i=0;i<n;i++) freq[arr1[i]]++;

        vector<int> ans;
        for(int i=0;i<(int)arr2.size();i++){
            while(freq[arr2[i]]>0) {
            ans.push_back(arr2[i]);
            freq[arr2[i]]--;
       } }
        for(int i=0;i<maxi+1;i++){
            while(freq[i]>0){ 
            ans.push_back(i);
            freq[i]--;
        }}
        return ans;
    }
};