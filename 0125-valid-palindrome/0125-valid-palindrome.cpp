class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";

        // Remove non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalpha(c) || isdigit(c)) {
                a += tolower(c);
            }
        }

        int l = 0, r = a.size() - 1;
        while (l < r) {
            if (a[l] != a[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};
