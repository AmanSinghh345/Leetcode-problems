class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]<0 && arr[j]*2 == arr[i]) return true;
                if((2*arr[i]-arr[j])==0) return true;
            }
        }
        return false;
    }
};