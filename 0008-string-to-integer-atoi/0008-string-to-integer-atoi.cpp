class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // 1. Skip leading whitespaces
        while(i < n && s[i] == ' ') i++;

        // 2. Check for sign
        bool sign = true; // true means positive
        if(i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '+');
            i++;
        }

        // 3. Parse digits
        long long ans = 0;
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            // 4. Clamp if out of bounds
            if(sign && ans > INT_MAX) return INT_MAX;
            if(!sign && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign ? ans : -ans;
    }
};
