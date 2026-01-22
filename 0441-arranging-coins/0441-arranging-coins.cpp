class Solution {
public:
    int arrangeCoins(int n) {
        
       long long ans= (-1 + sqrt(1- (4*(1LL*-1*2*n))))/2;
       return ans;
    }
};