class Solution {
public:
    int minimumCost(vector<int>& arr) {

         int n=arr.size();
    int count=0;
    int total=0;
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(count==2) count=0;
        else {
            total+=arr[i];
            count++;
        }
    }
         return total;
    }
};