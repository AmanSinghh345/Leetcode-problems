class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
       vector<int> freq(20001,0);
       int n=nums.size();
       for(int i=0;i<n;i++) freq[nums[i]+10000]++;

       int cnt=0;
       bool take=true;
       for(int i=0;i<20001;i++){
        while(freq[i]--){
            if(take)
            cnt+=(i-10000);
            take=!take;
        }
       }
       return cnt;
    }
};