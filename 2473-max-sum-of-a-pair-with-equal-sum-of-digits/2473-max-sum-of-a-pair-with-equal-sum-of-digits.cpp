class Solution {
public:
    int find(int x){
        int res=0;
        while(x>0){
            res +=x%10;
            x/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<n;i++){
            int digitSum=find(nums[i]);
            umap[digitSum].push_back(nums[i]);
        }
        int maxi=-1;
        for(auto&[x,arr]:umap){
             int ans=0;
            if(arr.size()>=2){
                 sort(arr.rbegin(), arr.rend());  
                 maxi = max(maxi, arr[0] + arr[1]);  
               
            }
        }
       
        return maxi;
    }
};