class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
            int n=nums.size();
            if(n<=2) return n;
            int bit_len=32-__builtin_clz(n);
            cout<<bit_len<<endl;
            return 1<<(bit_len);
    }
};