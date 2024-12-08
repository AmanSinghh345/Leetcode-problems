class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
           int start=logs[i][0];
           int end=logs[i][1];
           while(start<end){
            mpp[start]+=1;
            start++;
           }
        }
        //Now to find maximum
        int maxi=INT_MIN;
        int ans=0;
        for(auto& ele : mpp){
            if(ele.second>maxi){
                maxi=ele.second;
             ans=ele.first;
            }
            else if(ele.second==maxi && ele.first<ans)
            ans=ele.first;
        }
        return ans;
    }
};