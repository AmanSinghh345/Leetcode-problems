class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(1==__builtin_popcount(n)) return true;
        return false;
    }
};