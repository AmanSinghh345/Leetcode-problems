class Solution {
    vector<long long> factorials;

    // Count permutations of digits, excluding those with leading 0
    long long countPermutations(vector<int>& digitFreq, int totalDigits) {
        long long totalPerms = factorials[totalDigits];
        for (int i = 0; i < 10; i++) {
            totalPerms /= factorials[digitFreq[i]];
        }

        // Subtract permutations with leading zero
        if (digitFreq[0] > 0) {
            vector<int> temp = digitFreq;
            temp[0]--;
            long long leadingZeroPerms = factorials[totalDigits - 1];
            for (int i = 0; i < 10; i++) {
                leadingZeroPerms /= factorials[temp[i]];
            }
            totalPerms -= leadingZeroPerms;
        }

        return totalPerms;
    }

    // Unique signature string from digit frequency
    string getFrequencySignature(vector<int>& freq) {
        string sig = "";
        for (int i = 0; i < 10; i++) {
            sig += to_string(freq[i]) + "#";
        }
        return sig;
    }

    // Construct full palindrome from its half
    string buildPalindrome(int half, int length) {
        string halfStr = to_string(half);
        string mirror = halfStr;
        if (length % 2 == 0) {
            reverse(mirror.begin(), mirror.end());
        } else {
            mirror = mirror.substr(0, mirror.size() - 1);
            reverse(mirror.begin(), mirror.end());
        }
        return halfStr + mirror;
    }

public:
    long long countGoodIntegers(int length, int k) {
        factorials = vector<long long>(length + 1, 1);
        for (int i = 1; i <= length; i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        unordered_set<string> seenSignatures;
        long long totalCount = 0;

        int halfLength = (length + 1) / 2;
        int start = (halfLength > 1) ? pow(10, halfLength - 1) : 1;
        int end = pow(10, halfLength);

        for (int half = start; half < end; half++) {
            string palindromeStr = buildPalindrome(half, length);
            long long number = stoll(palindromeStr);

            if (number % k != 0) continue;

            vector<int> digitFreq(10, 0);
            for (char digit : palindromeStr) {
                digitFreq[digit - '0']++;
            }

            string signature = getFrequencySignature(digitFreq);
            if (seenSignatures.count(signature)) continue;

            seenSignatures.insert(signature);
            totalCount += countPermutations(digitFreq, length);
        }

        return totalCount;
    }
};
