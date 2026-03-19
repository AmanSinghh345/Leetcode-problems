class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> missing;
        int req=1;
        for(int i=0;i<n;i++){
            for(int j=req;j<arr[i];j++){
                missing.push_back(j);
                if(missing.size()==k) return missing.back();
            }
            req=arr[i]+1;
        }

        int num=arr[n-1]+1;
        while(missing.size()<k){
            missing.push_back(num);
            num++;
        }
        return missing.back();
    }
};