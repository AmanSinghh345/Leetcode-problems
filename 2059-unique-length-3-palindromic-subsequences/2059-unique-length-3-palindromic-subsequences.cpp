class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        // To find all the characters
        unordered_set<char> letters;
        for (int i = 0; i < n; i++) {
            letters.insert(s[i]);
        }
        int ans = 0;
        // finding first and last index of every character present
        for (char letter : letters) {
            int first_index = -1;
            int last_index = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (first_index == -1)
                        first_index = i;
                    else
                        last_index = i;
                }
            }
            unordered_set<char> st;
            for (int i = first_index+1; i < last_index; i++) {
                st.insert(s[i]);
            }
            ans+=st.size();
        }
        return ans;
    }
};