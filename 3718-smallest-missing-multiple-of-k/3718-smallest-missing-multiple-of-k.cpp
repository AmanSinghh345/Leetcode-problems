class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(101,0);
        for(int x:nums) freq[x]++;
        
        int mul=k;
        while(mul<=100 and freq[mul]){
            mul+=k;
        }
        return mul;
    }
};