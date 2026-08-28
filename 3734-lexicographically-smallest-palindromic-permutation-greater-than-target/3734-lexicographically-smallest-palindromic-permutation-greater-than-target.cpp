class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        if (n == 1) {
            return s > target ? s : "";
        }

        vector<int> cnt(26);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        string odd = "";

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (odd != "") {
                    return "";
                }
                odd = string(1, 'a' + i);
            }
            cnt[i] /= 2;
        }

        string pre = "";

        auto check = [&](char c) {
            string left = pre;
            left += c;

            for (int i = 25; i >= 0; i--) {
                left.append(cnt[i], 'a' + i);
            }

            string rev = left;
            reverse(rev.begin(), rev.end());

            string pal = left + odd + rev;

            return pal > target;
        };

        for (int i = 0; i < n / 2; i++) {
            bool ok = false;

            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }

                cnt[j]--;

                if (check('a' + j)) {
                    pre += 'a' + j;
                    ok = true;
                    break;
                }

                cnt[j]++;
            }

            if (!ok) {
                return "";
            }

            if (pre[i] > target[i]) {
                string left = pre;

                for (int j = 0; j < 26; j++) {
                    left.append(cnt[j], 'a' + j);
                }

                string rev = left;
                reverse(rev.begin(), rev.end());

                return left + odd + rev;
            }
        }

        string rev = pre;
        reverse(rev.begin(), rev.end());

        return pre + odd + rev;
    }
};