class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        int maxfreq = 0;
        
        for (char c : s) {
            umap[c]++;
            maxfreq = max(maxfreq, umap[c]);
        }

        vector<vector<char>> bucket(maxfreq + 1);
        for (auto& [ch, freq] : umap) {
            bucket[freq].push_back(ch);
        }

        string ans = "";
        for (int i = maxfreq; i >= 1; i--) {
            for (char ch : bucket[i]) {
                ans += string(i, ch);
            }
        }

        return ans;

        // tc: O(n), sc: O(n)
    }
};
