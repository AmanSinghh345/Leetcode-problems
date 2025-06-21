class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> umap;
        while (r < n) {
            umap[fruits[r]]++;
            while (umap.size() > 2) {
                umap[fruits[l]]--;

                if (umap[fruits[l]] == 0) {
                    umap.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};