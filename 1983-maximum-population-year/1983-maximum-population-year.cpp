class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Prefix Sum solution 
        vector<int> arr(101,0); // From the constrainsts
        for(const auto& log : logs){
            arr[log[0]-1950]++;
            arr[log[1]-1950]--;
        }
        int maxi=arr[0];
        int ans=1950;
        for(int i=1;i<101;++i){
            arr[i]+=arr[i-1];
            if(arr[i]>maxi){
                maxi=arr[i];
                ans=1950+i;
            }
        }
        return ans;
    }
};