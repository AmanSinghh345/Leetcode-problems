class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int x : nums){
            int sum=0;
            while(x>0){
                sum+=(x%10);
                x/=10;
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};