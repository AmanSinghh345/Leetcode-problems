class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            // prefix.push_back(prefix_sum);
        }
        int ans=0;
        long long  currsum=0;
        for(int i=0;i<n-1;i++){
            currsum+=nums[i];
            if(currsum>=sum-currsum) ans++;
        }
        return ans;
    }
};