class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int maxXor=1;
        while(maxXor<=maxi){
            maxXor*=2;
        }
        int n=nums.size();
        vector<int> doubleXor(maxXor,0),tripleXor(maxXor,0);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int val=nums[i]^nums[j];
                doubleXor[val]=1;
            }
        }

        for(int i=0;i<maxXor;i++){
            if(doubleXor[i]){
                for(int x:nums){
                    tripleXor[x^i]=1;
                }
            }
        }
        int cnt=0;
        for(int x:tripleXor){
            if(x) cnt++;
        }
        return cnt;
    }
};