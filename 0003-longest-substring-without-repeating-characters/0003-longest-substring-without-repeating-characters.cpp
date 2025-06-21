class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0;
        int r = 0;
        int maxi = 0;

        for (int r = 0; r < s.size(); r++) {
            while (st.find(s[r])!=st.end()) {
                st.erase(s[l]);
                l += 1;
            }
            st.insert(s[r]);
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};