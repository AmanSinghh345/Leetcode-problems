class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cur=-1;
        int cnt=0;
        int ele;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==1) {
                ele=cur;
                break;
            }
            if(nums[i]!=cur){ 
                cur=nums[i];
                ele =cur;
                cnt=1;
                }
            if(i<=n-3 &&(cur==nums[i+1] && cur==nums[i+2])  ) cnt+=2;
           
        }
        return ele;
    }
};