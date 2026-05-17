class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long l = *max_element(nums.begin(), nums.end());
    
        long long r=accumulate(nums.begin(),nums.end(),0LL);
        
        while(l<r){
            long long mid=l+(r-l)/2;
            int cnt=1;
            long long curr=0;
            for(int i=0;i<n;i++){
                
                if(curr+nums[i]>mid){
                    cnt++;
                    curr=nums[i];
                }
                else curr+=nums[i];
            }
           
            if(cnt<=k){
            
                r=mid;
            }
            else l=mid+1;
        }

    return l;
    }
};