class Solution {
public:
    int limit;
    long long nCrLimited(int n, int r, long long limit) {
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
    long long duplicatePermutation(vector<int>& freq) {
        long long n=0;
        for(int x:freq) n+=x;
        long long res=1;
        for(int i=0;i<26;i++){
             long long val=nCrLimited(n,freq[i],limit);
             if(res>limit/val) return limit;
             res*=nCrLimited(n,freq[i],limit);
             n-=freq[i];
        }
        return res;
    }
    string kthPermutation(vector<int>& freq, int k) {
        string ans = "";
        int n = 0;
        for (int x : freq)
            n += x;

        while (ans.size() < n) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] == 0)
                    continue;
                freq[i]--;
                long long total = duplicatePermutation(freq);
                freq[i]++;
                if (total >= k) {
                    ans += ('a' + i);
                    freq[i]--;
                    break;
                } else
                    k -= total;
            }
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        limit=k;
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        bool found = false;
        char ch;
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                if (found == true)
                    return "";
                found = true;
                ch = 'a' + i;
                freq[i]--;
            }
            freq[i] /= 2;
        }

        long long tt = duplicatePermutation(freq);
        if (tt < k)
            return "";
        string left = kthPermutation(freq, k);
        string right = left;
        reverse(right.begin(), right.end());
        if (found)
            return left + ch + right;
        return left + right;
    }
};