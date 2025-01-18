class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        
        // Store heights and names as pairs
        vector<pair<int, string>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({heights[i], names[i]});
        }
        
        // Sort in descending order of heights
        sort(v.begin(), v.end(), [](pair<int, string>& a, pair<int, string>& b) {
            return a.first > b.first;
        });
        
        // Extract sorted names
        vector<string> ans;
        for (auto& p : v) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
