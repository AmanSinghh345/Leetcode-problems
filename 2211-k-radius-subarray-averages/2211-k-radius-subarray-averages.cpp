class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n);
        long long  prefixSum=0;
        vector<long long > prefix(n,0);
        prefixSum=nums[0];
        prefix[0]=prefixSum;
        for(int i=1;i<n;i++){
            prefixSum+=nums[i];
            prefix[i]+=prefixSum;
        }
        for(int i=0;i<n;i++){
            if(i-k<0 or i+k>n-1){
                ans[i]=-1;
                continue;
            }
            long long  sum;
            if(i-k==0) sum=prefix[i+k];
            else
             sum=prefix[i+k]-prefix[i-k-1];
             int N=i+k-(i-k)+1;
            int  avg=sum/N;
             ans[i]=avg;

        }
        return ans;
    }
};