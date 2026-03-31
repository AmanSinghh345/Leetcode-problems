#include <string>
#include <vector>

using namespace std;

#define ll long long 

class Solution {
    // Two large prime moduli
    ll mod1 = 1e9 + 7;
    ll mod2 = 1e9 + 9;
    
    // Two different radices (bases)
    ll Radix1 = 26;
    ll Radix2 = 31; 

public:
    int strStr(string haystack, string needle) {
        ll n = haystack.size();
        ll m = needle.size();
        
        if (m == 0) return 0;
        if (n < m) return -1;

        ll maxWeight1 = 1, maxWeight2 = 1;
        ll hashNeedle1 = 0, hashNeedle2 = 0;
        ll hashHay1 = 0, hashHay2 = 0;

        // 1. Precompute Max Weights: Radix^(m-1) % mod
        for (ll i = 1; i < m; i++) {
            maxWeight1 = (maxWeight1 * Radix1) % mod1;
            maxWeight2 = (maxWeight2 * Radix2) % mod2;
        }

        // 2. Compute initial hashes for the needle and the first window of haystack
        for (ll i = 0; i < m; i++) {
            ll valNeedle = needle[i] - 'a';
            ll valHay = haystack[i] - 'a';

            hashNeedle1 = (hashNeedle1 * Radix1 + valNeedle) % mod1;
            hashNeedle2 = (hashNeedle2 * Radix2 + valNeedle) % mod2;

            hashHay1 = (hashHay1 * Radix1 + valHay) % mod1;
            hashHay2 = (hashHay2 * Radix2 + valHay) % mod2;
        }

        // 3. Slide the window
        for (ll i = 0; i <= n - m; i++) {
            // If BOTH hashes match, it's a guaranteed match. No substr() needed!
            if (hashHay1 == hashNeedle1 && hashHay2 == hashNeedle2) {
                return i;
            }

            // Roll the hashes for the next window
            if (i < n - m) {
                ll removedChar = haystack[i] - 'a';
                ll addedChar = haystack[i + m] - 'a';

                // Update Hash 1
                hashHay1 = (hashHay1 - (removedChar * maxWeight1) % mod1 + mod1) % mod1;
                hashHay1 = (hashHay1 * Radix1 + addedChar) % mod1;

                // Update Hash 2
                hashHay2 = (hashHay2 - (removedChar * maxWeight2) % mod2 + mod2) % mod2;
                hashHay2 = (hashHay2 * Radix2 + addedChar) % mod2;
            }
        }

        return -1;
    }
};