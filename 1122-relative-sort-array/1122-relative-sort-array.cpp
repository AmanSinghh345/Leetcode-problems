class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi=*max_element(arr1.begin(),arr1.end());
        vector<int> freq(maxi+1,0);
        vector<int> present(maxi+1,-1);
        int n=arr1.size();
        for(int i=0;i<n;i++) present[arr1[i]]=1;
        for(int i=0;i<(int)arr2.size();i++) present[arr2[i]]=2;
        for(int i=0;i<n;i++) freq[arr1[i]]++;

        vector<int> ans;
        for(int i=0;i<(int)arr2.size();i++){
            while(freq[arr2[i]]--) {
                ans.push_back(arr2[i]);
            }
        }
        vector<int> temp;
        for(int i=0;i<n;i++) {
            if(present[arr1[i]]==1 ) temp.push_back(arr1[i]);
        }
        sort(temp.begin(),temp.end());
        for(int x:temp) ans.push_back(x);
        return ans;
    }
};