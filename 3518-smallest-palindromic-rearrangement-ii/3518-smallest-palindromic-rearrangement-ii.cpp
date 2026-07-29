class Solution {
public:
    long long combinationLimited(int n, int r, long long limit) {
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            __int128 cur = (__int128)res * (n - r + i);
            cur /= i;

            if (cur > limit)
                return limit + 1;

            res = (long long)cur;
        }

        return res;
    }

    long long countPermutations(vector<int>& freq, long long limit) {
        int remaining = 0;
        for (int x : freq)
            remaining += x;

        long long ans = 1;

        for (int f : freq) {
            if (f == 0)
                continue;

            long long ways = combinationLimited(remaining, f, limit);

            __int128 cur = (__int128)ans * ways;
            if (cur > limit)
                return limit + 1;

            ans = (long long)cur;
            remaining -= f;
        }

        return ans;
    }

    string buildKthPermutation(vector<int>& freq, long long k) {
        int len = 0;
        for (int x : freq)
            len += x;

        string ans;

        while ((int)ans.size() < len) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0)
                    continue;

                freq[c]--;

                long long ways = countPermutations(freq, k);

                if (ways >= k) {
                    ans.push_back('a' + c);
                    break;
                }

                k -= ways;
                freq[c]++;
            }
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                if (middle)
                    return "";
                middle = 'a' + i;
                freq[i]--;
            }
            freq[i] /= 2;
        }

        if (countPermutations(freq, k) < k)
            return "";

        string left = buildKthPermutation(freq, k);
        string right = left;
        reverse(right.begin(), right.end());

        if (middle)
            return left + middle + right;

        return left + right;
    }
};