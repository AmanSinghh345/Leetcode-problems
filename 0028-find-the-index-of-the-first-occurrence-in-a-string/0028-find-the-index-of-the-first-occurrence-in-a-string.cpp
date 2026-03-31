#define ll long long 
int mod = 1e9+7;

class Solution {
public:
    ll hashvalue(string s, ll Radix, ll m) {
        ll factor = 1;
        ll res = 0;
        // Calculate hash for the first m characters
        for (int i = m - 1; i >= 0; i--) {
            res = (res + (s[i] - 'a') * factor) % mod;
            factor = (factor * Radix) % mod;
        }
        return res;
    }

    int strStr(string haystack, string needle) {
        ll n = haystack.size();
        ll m = needle.size();
        if (n < m) return -1;
        if (m == 0) return 0;

        ll Radix = 26;
        ll Max_Weight = 1;
        
        // Max_Weight should be Radix^(m-1)
        for (ll i = 1; i < m; i++) {
            Max_Weight = (Max_Weight * Radix) % mod;
        }
       
        ll hashNeedle = hashvalue(needle, Radix, m);
        ll hashHay = 0;

        // Loop should stop at n - m
        for (ll i = 0; i <= n - m; i++) {
            if (i == 0) {
                hashHay = hashvalue(haystack, Radix, m); // Fixed function call
            } else {
                // Rolling Hash logic:
                // 1. Remove leading char: (hashHay - char * Max_Weight)
                // 2. Shift left: * Radix
                // 3. Add trailing char: + newChar
                ll removedChar = (haystack[i - 1] - 'a');
                ll addedChar = (haystack[i + m - 1] - 'a');
                
                hashHay = (hashHay - (removedChar * Max_Weight) % mod + mod) % mod;
                hashHay = (hashHay * Radix + addedChar) % mod;
            }

            if (hashHay == hashNeedle) {
                // To be 100% safe from collisions, check the actual string
                if (haystack.substr(i, m) == needle) return i;
            }
        }
        return -1;
    }
};