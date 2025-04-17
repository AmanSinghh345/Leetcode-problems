class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=n-1;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] and (i*j)%k==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};