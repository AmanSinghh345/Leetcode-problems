class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++) arr.push_back({nums[i],i});
        sort(arr.begin(),arr.end());
        int l=0,r=n-1;
        while(l<r){
            int val1=arr[l].first;
            int val2=arr[r].first;
            int sum=val1+val2;
            if(sum==target) return {arr[l].second,arr[r].second};
           else if(sum<target) l++;
            else r--;
        }   
        return {-1,-1};
    }
};