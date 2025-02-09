class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = 1LL * n * (n - 1) / 2;
        
        unordered_map<int, long long> umap;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            if (umap.find(key) != umap.end()) {
                goodPairs += umap[key];
            }
            umap[key]++;
        }
        
        return total - goodPairs;
    }
};
