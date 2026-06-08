class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        map<int,int> freq;
        int sum=0;
        freq[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=(sum%k+k)%k;
            if(freq.count(rem)){
                cnt+=freq[rem];
            }
            freq[rem]++;

        }
        return cnt;
    }
};