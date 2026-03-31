#include <string>
using namespace std;

#define ll long long 

class Solution {
    ll mod = 1e9 + 7;
    ll Radix = 26;


    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (n < m) return -1;

        ll hashNeedle = 0, hashHay = 0, maxWeight = 1;

        for (int i = 0; i < m; i++) {
            hashNeedle = (hashNeedle * Radix + (needle[i] - 'a')) % mod;
            hashHay = (hashHay * Radix + (haystack[i] - 'a')) % mod;
            if (i < m - 1) maxWeight = (maxWeight * Radix) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            if (hashHay == hashNeedle) {
                if (haystack.substr(i, m) == needle) return i;
            }

            if (i < n - m) {
                ll removedChar = haystack[i] - 'a';
                ll addedChar = haystack[i + m] - 'a';
                
                hashHay = (hashHay - (removedChar * maxWeight) % mod + mod) % mod;
                hashHay = (hashHay * Radix + addedChar) % mod;
            }
        }
        return -1;
    }

public:
    int repeatedStringMatch(string a, string b) {
        // 1. Calculate minimum repeats to at least match b's length
        int q = b.length() / a.length();
        if (b.length() % a.length() != 0) {
            q++; // Ceiling division
        }

        // 2. Build the repeated haystack
        string haystack = "";
        for (int i = 0; i < q; i++) {
            haystack += a;
        }

        // 3. Check if b is in a repeated 'q' times using Rabin-Karp
        if (strStr(haystack, b) != -1) {
            return q;
        }

        // 4. Check the cross-boundary edge case (q + 1 times)
        haystack += a;
        if (strStr(haystack, b) != -1) {
            return q + 1;
        }

        // 5. If not found in either, it's impossible
        return -1;
    }
};