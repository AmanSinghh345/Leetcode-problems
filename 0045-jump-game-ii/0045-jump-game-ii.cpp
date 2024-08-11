class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            r = max(r, nums.at(i) + i);
            if (l == i) {
                jumps++;
                l = r;
            }
        }
    return jumps;
    
    }
};